<img width="752" height="664" alt="image" src="https://github.com/user-attachments/assets/5c50994c-c8bb-4acd-b72d-304df18cdab0" />

A simple, free and open-source text editor in C++11 and SDL2 GUI framework. I coded it using Visual Studio 2022 editor and managed by CMake build generator.

## Features
- Supports typing of every displayable characters with the Shift and Ctrl modifiers. (Brace yourself for surprises)
- Can save the text to a file named FILE on Ctrl+S and read from FILE on Ctrl+O.

## How to run the sourcecode?
The steps to run are quite easy to explain (pun intended):
- Download the source code from here <img width="1172" height="675" alt="image" src="https://github.com/user-attachments/assets/37fdd435-370b-4693-86c0-4aabf57deb72" />
- Make sure that you have Visual Studio 2022 installed in your PC (bloatware). If not, download and install it from https://visualstudio.microsoft.com/vs/older-downloads/
- Now set up this project in your Visual Studio 2022 as File > Open > CMake
- Select the CMakeLists.txt <img width="954" height="539" alt="image" src="https://github.com/user-attachments/assets/07e321e1-2a11-42cf-829f-9afcf7d57620" />
- You'll get this screen on your Visual Studio editor <img width="1920" height="710" alt="image" src="https://github.com/user-attachments/assets/df6872d8-024b-45c9-a50d-84fa6ff0bf45" />
- The initial CMake build will fail. To fix the CMake build, in the CMakeLists.txt, you'll find three paths 
  `set(CMAKE_MODULE_PATH "C:/Development/CMake/modules")`
  `set(SDL2_PATH "C:/Development/Library/SDL2-2.30.6")`
  `set(SDL2_TTF_PATH "C:/Development/Library/SDL2_ttf-2.22.0")`
- You should set these paths on your PC as in the image <img width="964" height="240" alt="image" src="https://github.com/user-attachments/assets/e454cf25-8dec-47c3-9a67-a29a360da014" />
- Download the [SDL2](https://github.com/libsdl-org/SDL/releases?q=2.30.6&expanded=true) and [SDL2_ttf](https://github.com/libsdl-org/SDL_ttf/releases?q=2.22.0&expanded=true) packages as SDL2-2.30.6-win32-x64 and SDL2_ttf-2.22.0-win32-x64, respectively.
- Extract them in the C:/Development/Library/ folder.
- Then download FindSDL2.cmake and FindSDL2_ttf.cmake https://github.com/tcbrindle/sdl2-cmake-scripts, and place them in the C:/Development/CMake/modules folder
- Once done, Ctrl+S the CMakeLists.txt and it should end up build as <img width="1438" height="281" alt="image" src="https://github.com/user-attachments/assets/d67a67cf-c13b-454b-afcb-660b380783d7" />
- Now Ctrl+F5 in the Visual Studio 2022 Editor and you'll find the windows pop-up as <img width="1138" height="745" alt="image" src="https://github.com/user-attachments/assets/0bfc5fd0-93ee-4dc2-831d-6e560a17139a" />
- Start typing anything you want to.
- Save using Ctrl+S, and exit using Shift+Tab
- Rerun the program, and open your saved work with Ctrl+O
