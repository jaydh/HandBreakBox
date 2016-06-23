// HandBreakBox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HandBreakBox.h"
#include<string>
#include<boost/filesystem.hpp>
#include<queue>
#include<unordered_set>
#include<string>
#include<VideoFile.h>
#include<shellapi.h>
#include<iostream>

using namespace std;
using namespace boost::filesystem;


queue<path> getFileList(const path &dirPath) {
	const static std::unordered_set<std::string> videoFileExtensions{ ".mkv", ".mp4" };
	queue<path> myQueue;

	recursive_directory_iterator dir(dirPath);
	recursive_directory_iterator end;
	for (; dir != end; ++dir) {
		path currentPath = *dir;
		path currentFileExtension = currentPath.extension();
		
		//Only adds video files to queue
		if (videoFileExtensions.count(currentFileExtension.string())) {myQueue.push(currentPath);}
	}
	return myQueue;
}

void processFiles(queue<path> videoFiles) {
	while (!videoFiles.empty()) {
		path tempIn = videoFiles.front();
		string newFileName = "Converted " + tempIn.filename().string();
		path tempOut(tempIn.parent_path());
		tempOut /= path(newFileName);
		cout << tempIn << endl;
		cout << tempOut << endl;
		VideoFile test(tempIn, tempOut, "--preset = \"Normal\"");
		test.process();
		videoFiles.pop();
	}
}

int main() {
	path syncFolderPath = path("C:\\Users\\jay\\Videos");
	queue<path> filesToConvert = getFileList(syncFolderPath);
	processFiles(filesToConvert);
	cin.get();
}