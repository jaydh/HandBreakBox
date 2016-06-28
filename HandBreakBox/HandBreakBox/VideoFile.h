#pragma once
#include<boost/filesystem.hpp>
#include<boost/chrono.hpp>

using namespace std;
using namespace boost::filesystem;

class VideoFile {

public:
	VideoFile(path otherIn, path otherOut, path HandBrakeLocation = "C:\\HandBrakeCLI.exe -i \"", string flags =
		"-e x264  -q 20.0 -a 1,1 -E faac,copy:ac3 -B 160,160 -6 dpl2,none -R Auto,Auto -D 0.0,0.0 --audio-copy-mask aac,ac3,dtshd,dts,mp3 --audio-fallback ffac3 -f mp4 -4 --decomb --loose-anamorphic --modulus 2 -m --x264-preset medium --h264-profile high --h264-level 4.1");

	void setInPath(path const& otherIn) { inPath = otherIn; }
	void setOutPath(path const& otherOut) { outPath = otherOut; }
	void setFlags(string const & otherFlags) { flags = otherFlags; }
	bool isProcessed() const { return processedStatus; }
	path getInPath() const { return inPath; }
	path getOutPath() const { return outPath; }
	int static getVideoFileCount() { return VideoFileCount; }

	void process();

private:
	void callHandBrakeCLI();
	static int VideoFileCount;
	path inPath;
	path outPath;
	path HandBrakeLocation;
	string flags;
	bool processedStatus;
};