#pragma once
#include<queue>
#include<VideoFile.h>
#include<unordered_set>
#include<iostream>
#include<boost/optional.hpp>

using namespace std;
using namespace boost::filesystem;

class FileManager {
public:

	FileManager(path syncFolder, path outputFolder);

	//Uses recursive directory iterators to push Video Files to videosToConvert Queue.
	void updateFileList();
	//Use aux queue to print entries. Might implement queue from vector later to avoid print limitation
	void printFileList(ostream& o = cout) const;

	void processFiles();

private:
	queue<VideoFile> videoFileQueue;
	path parentInputFolder;
	path parentOutputFolder;
	string flags;
	unordered_set<std::string> videoFileExtensions{ ".mkv", ".mp4" };
};