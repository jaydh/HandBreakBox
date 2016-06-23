#include "resource.h"
#include<FileManager.h>

using namespace std;
using namespace boost::filesystem;

FileManager::FileManager(path syncFolder, path outputFolder): syncFolder(syncFolder), outputFolder(outputFolder), flags(flags) {}

void FileManager::getFileList() {
	
	recursive_directory_iterator dir(syncFolder), end;
	for (; dir != end; ++dir) {
		path currentPath = *dir;
		path currentFileExtension = currentPath.extension();

		//Only adds video files to queue
		if (videoFileExtensions.count(currentFileExtension.string())) { 
			//Keeps directory hiearachy in output folder
			path currentOut(outputFolder);
			path relativePath = relative(currentPath, syncFolder);
			currentOut /= relativePath;

			toConvert.push(VideoFile(currentPath, currentOut)); 
		}
	}
}

void FileManager::printFileList() {
	queue<VideoFile> aux(toConvert);
	while (!aux.empty()) {
		cout << aux.front().getInPath() << endl;
		aux.pop();
	}
}

void FileManager::processFiles(string flags) {
	while (!toConvert.empty()) {
		VideoFile temp = toConvert.front();
		temp.setFlags(flags);
		temp.process();
		toConvert.pop();
	}
}
