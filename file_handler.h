#pragma once

#include <map>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(map<int, string>);
pair<map<int, string>, int> readFromFile();