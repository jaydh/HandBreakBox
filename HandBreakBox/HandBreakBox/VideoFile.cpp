#include<boost/filesystem.hpp>
#include<Windows.h>
#include<shellapi.h>
#include<string>
#include<VideoFile.h>
#include<iostream>
using namespace std;
using namespace boost::filesystem;


VideoFile::VideoFile(path otherIn, path otherOut, path HandBrakeLocation, string flags) :inPath(otherIn), outPath(otherOut), HandBrakeLocation(HandBrakeLocation), flags(flags) {
	//if (otherIn == nullptr) { throw invalid_argument; }
	VideoFileCount += 1;
	processedStatus = (is_regular_file(outPath)) ? true : false;
}
	
void VideoFile::process() {
	if (!isProcessed()) {
		callHandBrakeCLI();
		processedStatus = true;
	}
}

//I know system calls are evil, will move to ShellExecute/CreateProcess when I figure out how to make it work with HandBrakeCLI
void VideoFile::callHandBrakeCLI() {
		
		//Generates the encode flags to be used by ShellExecute
		string Flags = HandBrakeLocation.string() + inPath.string() + "\" -o \"" + outPath.string() + "\" " + flags;
		const char* formattedFlags = Flags.c_str();
		
		cout << formattedFlags << endl;

		system(formattedFlags);
		
	}
