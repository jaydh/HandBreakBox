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
	void printFileList(ostream& o);

	void processFiles(string flags = " - e x264 - q 20.0 - a 1, 1 - E faac, copy:ac3 - B 160, 160 - 6 dpl2, none - R Auto, Auto - D 0.0, 0.0 --audio - copy - mask aac, ac3, dtshd, dts, mp3 --audio - fallback ffac3 - f mp4 - 4 --decomb --loose - anamorphic --modulus 2 - m --x264 - preset medium --h264 - profile high --h264 - level 4.1");
	
private:
	queue<VideoFile> toConvert;
	path syncFolder;
	path outputFolder;
	string flags;
	unordered_set<std::string> videoFileExtensions{ ".mkv", ".mp4" };
};