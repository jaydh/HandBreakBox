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
		path currentFileExtension = currentInPath.extension();

		//Matches input directory hiearchy for output folder
		path currentOutPath(parentOutputFolder);
		currentOutPath /= relative(currentInPath, parentInputFolder) /= currentInPath.filename() /= currentInPath.extension();

		//Precondition: path extension matches video file extensions and currentOut doesn't point to a file that's already been converted
		if (videoFileExtensions.count(currentFileExtension.string()) && !is_regular_file(currentOutPath)) {
			inputVideoFiles.push_back(VideoFile(currentInPath));
			VideoFileCount += 1;
		}
	}

}

void FileManager::printInputFileList(ostream& o) const {
	for (auto file : inputVideoFiles) {
		o << file.getPath() << endl;
	}
}
void FileManager::printOutputFileList(ostream& o) const {
	for (auto file : inputVideoFiles) {
		o << file.getPath() << endl;
	}
}

void FileManager::processNextFile() {
	
	VideoFile current = inputVideoFiles.front();
	process(current);
	inputVideoFiles.pop_back();
	
}

void FileManager::process(VideoFile in) {

	path outDir(parentOutputFolder);
	outDir /= relative(in.getPath(), parentInputFolder);
	path outPath(outDir);
	outPath /= in.getPath().filename() /= in.getPath().extension();

	if (!is_directory(outDir)) { create_directories(outDir); }

	//Generates the encode flags to be used by ShellExecute
	string Flags = HandBrakeLocation.string() + " -i " + in.getPath().string() + "\" -o \"" + outPath.string() + "\" " + flags;
	system(Flags.c_str()); 
		
}

