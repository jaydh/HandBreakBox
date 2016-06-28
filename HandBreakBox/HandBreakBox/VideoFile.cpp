#include<boost/filesystem.hpp>
#include<Windows.h>
#include<shellapi.h>
#include<string>
#include<VideoFile.h>
#include<iostream>
using namespace std;
using namespace boost::filesystem;

VideoFile::VideoFile(path other) : filePath(other){

	processedStatus = false;
	inFileSize = file_size(filePath);
}