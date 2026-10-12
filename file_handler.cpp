#include "file_handler.h"
#include "init.h"

void writeToFile(map<int, string> cursorSentenceMap) {
	SDL_LogInfo(0, "main: Ctrl + S");
	ofstream outFile("FILE");
	if (!outFile) {
		SDL_LogError(0, "main: Cannot open file!");
		exit(EXIT_FAILURE);
	}
	map<int, string>::iterator it;
	for (it = cursorSentenceMap.begin(); it != cursorSentenceMap.end(); it++) {
		outFile << it->second.c_str() << endl;
	}

	outFile.close();
}

pair<map<int, string>, int> readFromFile() {
	SDL_LogInfo(0, "main: Ctrl + O");
	ifstream inFile("FILE");
	if (!inFile) {
		SDL_LogError(0, "main: Cannot open file!");
		exit(EXIT_FAILURE);
	}
	map<int, string> cursorSentenceMap;
	int cursor = 0;
	string str;
	while (getline(inFile, str))
	{
		cursorSentenceMap.insert(pair<int, string>(cursor, str));
		cursor++;
	}
	inFile.close();
	return make_pair(cursorSentenceMap, cursor);
}