// HandBreakBox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HandBreakBox.h"
#include<string>
#include<Boost/filesystem.hpp>
#include<queue>
#include<unordered_set>
#include<string>
using namespace std;
using namespace boost::filesystem;

const static std::unordered_set<std::string> videoFileExtensions {".mkv", ".mp4" };

//change to vidoefile

queue<path> & getFileList(const path& dirPath, queue<path> & videoFiles) {
	recursive_directory_iterator dir(dirPath), end;
	for (; dir != end; dir++) {
		if (videoFileExtensions.count(dir->path.exention())) {
			videoFiles.push(dir->path);
		}
	}
	return;
}



int main() {
	queue<path> filesToConvert;
}