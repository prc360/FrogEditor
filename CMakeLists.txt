# CMakeList.txt : CMake project for CMakeStarter, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("FrogEditor")

set(CMAKE_CXX_STANDARD 11)

# Put the FindSDL2.cmake in a folder and tell CMake to find it there
set(CMAKE_MODULE_PATH "C:/Development/CMake/modules")

set(SDL2_PATH "C:/Development/Library/SDL2-2.30.6")

find_package(SDL2 REQUIRED)

set(SDL2_TTF_PATH "C:/Development/Library/SDL2_ttf-2.22.0")
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

file (GLOB_RECURSE FrogEditor_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE FrogEditor_HEADERS CONFIGURE_DEPENDS "src/headers/*.h")

set (FrogEditor_INCLUDE_DIRS "")
foreach (_headerFile ${FrogEditor_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND FrogEditor_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES FrogEditor_INCLUDE_DIRS)

# Add source to this project's executable.
add_executable (FrogEditor ${FrogEditor_SOURCES})

add_custom_command(TARGET FrogEditor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:FrogEditor>/fonts
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/fonts/OpenSans-Regular.ttf
        $<TARGET_FILE_DIR:FrogEditor>/fonts/
)   

target_include_directories(FrogEditor PRIVATE ${FrogEditor_INCLUDE_DIRS}) 

target_link_libraries(FrogEditor ${SDL2_LIBRARY}
        ${SDL2_TTF_LIBRARY})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FrogEditor PROPERTY CXX_STANDARD 11)
endif()

# TODO: Add tests and install targets if needed.
