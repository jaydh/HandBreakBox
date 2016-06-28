#include "resource.h"
#include<FileManager.h>

using namespace std;
using namespace boost::filesystem;

FileManager::FileManager(path in, path out): parentInputFolder(in), parentOutputFolder(out), flags(flags) {}

void FileManager::updateFileList() {
	
	//Start fresh. might consider new implementation for vector.clear
	 videoFileQueue.clear();

	recursive_directory_iterator dir(parentInputFolder), end;
	for (; dir != end; ++dir) {
		path currentInPath = *dir;
		path currentFileExtension = currentInPath.extension();

		//Matches input directory hiearchy for output folder
		path currentOutPath(parentOutputFolder);
		path relativePath = relative(currentInPath, parentInputFolder);
		currentOutPath /= relativePath;;
		
		//Precondition: path extension matches video file extensions and currentOut doesn't point to a file that's already been converted
		if (videoFileExtensions.count(currentFileExtension.string())) {
			videoFileQueue.push_back(VideoFile(currentInPath, currentOutPath)); 
		}
	}
}

void FileManager::printInputFileList(ostream& o) const {
	for (auto file : videoFileQueue) {
		o << file.getInPath() << endl;
	}
}

void FileManager::printOutputFileList(ostream& o) const {
	for (auto file : videoFileQueue) {
		o << file.getOutPath() << endl;
	}
}

//need to implement optional string for flags
void FileManager::processNextFile() {
	
	VideoFile current = videoFileQueue.front();
		
	//Creates subdirectories if they're not present
	if (!is_directory(current.getOutPath())) {	create_directories(current.getOutPath().parent_path()); }

	current.process();
	videoFileQueue.pop_back();
	
}
