#pragma once
#include<queue>
#include<VideoFile.h>
#include<unordered_set>
#include<iostream>
#include<boost/optional.hpp>
#include<algorithm>

using namespace std;
using namespace boost::filesystem;

class FileManager {
public:

	FileManager(path syncFolder, path outputFolder, path HandBrakeLocation = "C:\\HandBrakeCLI.exe\"", string flags =
			"-e x264  -q 20.0 -a 1,1 -E faac,copy:ac3 -B 160,160 -6 dpl2,none -R Auto,Auto -D 0.0,0.0 --audio-copy-mask aac,ac3,dtshd,dts,mp3 --audio-fallback ffac3 -f mp4 -4 --decomb --loose-anamorphic --modulus 2 -m --x264-preset medium --h264-profile high --h264-level 4.1");
	
	//Uses recursive directory iterators
	void updateFileList();

	void printInputFileList(ostream & o) const;
	int getVideoFileCount() const { return VideoFileCount; }
	void processNextFile();

	
private:
	void process(VideoFile vid);

	vector<VideoFile> VideoFiles;
	vector<VideoFile> ProcessedFiles;
	path parentInputFolder;
	path parentOutputFolder;

	path HandBrakeLocation;
	int VideoFileCount;
	string flags;
	unordered_set<std::string> videoFileExtensions{ ".mkv", ".mp4" };
};