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

	void printInputFileList(ostream & o) const;
	void printOutputFileList(ostream & o) const;

	void processNextFile();

private:
	vector<VideoFile> videoFileQueue;
	path parentInputFolder;
	path parentOutputFolder;
	string flags;
	unordered_set<std::string> videoFileExtensions{ ".mkv", ".mp4" };
};