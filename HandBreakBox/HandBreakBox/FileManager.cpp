#include "resource.h"
#include<FileManager.h>

using namespace std;
using namespace boost::filesystem;

FileManager::FileManager(path inputFolder, path outputFolder, path HandBrakeLocation, string flags): parentInputFolder(inputFolder), parentOutputFolder(outputFolder), flags(flags) {
	VideoFileCount = 0;
}

void FileManager::updateFileList() {
	
	recursive_directory_iterator dir(parentInputFolder), end;
	for (; dir != end; ++dir) {
		path currentInPath = *dir;
		
		//Precondition: path extension matches video file extensions and currentOut doesn't point to a file that's already been converted
		if (videoFileExtensions.count(currentInPath.extension().string()) && !VideoFile::inputPaths.count(currentInPath)) {
			//Matches input directory hiearchy for output folder
			path currentOutPath(parentOutputFolder);
			currentOutPath /= relative(currentInPath, parentInputFolder) /= currentInPath.filename() /= currentInPath.extension();

			VideoFiles.push_back(VideoFile(currentInPath, currentOutPath));
			VideoFileCount += 1;
		}
	}

}

void FileManager::printInputFileList(ostream& o) const {
	for (auto file : VideoFiles) {
		o << file.getInPath() << endl;
	}
}

void FileManager::processNextFile() {
	
	VideoFile current = VideoFiles.back();
	if (!is_regular_file(current.getOutPath())) {
		process(current);
		//check how the processing went
		current.setProcssedStatus(true);
	}

	VideoFiles.pop_back();
	//Note: VideoFiles::inputFiles still keeps inPath of objects pushed to ProcessedFiles
	ProcessedFiles.push_back(current);
}

void FileManager::process(VideoFile vid) {
	if (!is_directory(vid.getOutPath())) { create_directories(vid.getOutPath()); }
	//Generates the encode flags to be used by ShellExecute
	string Flags = HandBrakeLocation.string() + " -i " + vid.getInPath().string() + "\" -o \"" + vid.getOutPath().string() + "\" " + flags;
	system(Flags.c_str());

}
