#include<boost/filesystem.hpp>
#include<Windows.h>
#include<shellapi.h>
#include<string>
#include<VideoFile.h>
#include<iostream>
using namespace std;
using namespace boost::filesystem;

VideoFile::VideoFile(path otherIn, path otherOut) : inPath(otherIn), outPath(otherOut) {

	processedStatus = (is_regular_file(outPath)) ? true : false;
	inFileSize = file_size(inPath);
	inputPaths.insert(inPath);
}

VideoFile::~VideoFile(){
	inputPaths.erase(inPath);
}