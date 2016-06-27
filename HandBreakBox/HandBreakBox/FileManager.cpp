#include "resource.h"
#include<FileManager.h>

using namespace std;
using namespace boost::filesystem;

FileManager::FileManager(path syncFolder, path outputFolder): syncFolder(syncFolder), outputFolder(outputFolder), flags(flags) {}

void FileManager::updateFileList() {
	
	//Start fresh. might consider new implementation for vector.clear
	while (!videosToConvert.empty()) { videosToConvert.pop(); }

	recursive_directory_iterator dir(syncFolder), end;
	for (; dir != end; ++dir) {
		path currentPath = *dir;
		path currentFileExtension = currentPath.extension();

		//Matches input directory hiearchy for output folder
		path currentOut(outputFolder);
		path relativePath = relative(currentPath, syncFolder);
		currentOut /= relativePath;
		
		//Add video file to queue
		//Precondition: path extension matches video file extensions and currentOut doesn't point to a file that's already been converted
		//Alternative to output folder check is to use last access time to determine whether video files have been processed yet
		//Design choice: I can maintain all the video files in the list, and use the isProcessed Flag for conversion list. I.e. use timeCheck to maintain List of all VideoFiles
		if (!is_regular_file(currentOut) && videoFileExtensions.count(currentFileExtension.string())) {
			videosToConvert.push(VideoFile(currentPath, currentOut)); 
		}
	}
}

void FileManager::printFileList(ostream& o) {
	queue<VideoFile> aux(videosToConvert);
	while (!aux.empty()) {
		o << aux.front().getInPath() << endl;
		aux.pop();
	}
}

void FileManager::processFiles(string flags) {
	while (!videosToConvert.empty()) {

		//if timeOut break

		VideoFile temp = videosToConvert.front();
		
		//Creates subdirectories if they're not present
		if (!is_directory(temp.getOutPath())) {	create_directories(temp.getOutPath().parent_path()); }

		temp.setFlags(flags);
		temp.process();
		videosToConvert.pop();
	}
}
