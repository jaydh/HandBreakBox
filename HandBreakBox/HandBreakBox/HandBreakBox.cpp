// HandBreakBox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HandBreakBox.h"
#include<string>
#include<Boost/filesystem.hpp>
#include<queue>
#include<unordered_set>
#include<string>
#include<VideoFile.h>

using namespace std;
using namespace boost::filesystem;

const static std::unordered_set<std::string> videoFileExtensions {".mkv", ".mp4" };


queue<path> getFileList(const path& dirPath) {
	queue<path> myQueue;

	recursive_directory_iterator dir(dirPath), end;
	for (; dir != end; dir++) {
		path currentPath = *dir;
		path currentFileExtension = currentPath.extension();
		
		//Only adds video files to queue
		if (videoFileExtensions.count(currentFileExtension.string())) {myQueue.push(currentPath);}
	}
	return myQueue;
}



int main() {
	queue<path> filesToConvert = getFileList(path("C:\\Users\\jay\\Videos"));
	path temp = filesToConvert.pop;
	VideoFile test(temp, path("C:\\Users\\jay\\Videos\\test"));
	test.process();
}