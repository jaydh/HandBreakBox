#pragma once
#include<queue>
#include<VideoFile.h>
#include<unordered_set>
#include<iostream>

using namespace std;
using namespace boost::filesystem;


class FileManager {
public:

	FileManager(path syncFolder, path outputFolder);

	void getFileList();
	//Use aux queue to print entries. Might implement queue from vector later to avoid print limitation
	void printFileList();

	void processFiles(string flags = "--preset = \"High Profile\"");
	
private:
	queue<VideoFile> toConvert;
	path syncFolder;
	path outputFolder;
	string flags;
	unordered_set<std::string> videoFileExtensions{ ".mkv", ".mp4" };
};