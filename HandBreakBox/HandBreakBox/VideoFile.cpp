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
	processedStatus = false;
}
void VideoFile::setInPath(path const& otherIn) { inPath = otherIn; }
void VideoFile::setOutPath(path const& otherOut) { outPath = otherOut; }
void VideoFile::setFlags(string const & otherFlags) { flags = otherFlags; }
path VideoFile::getInPath() const { return inPath; }
path VideoFile::getOutPath() const { return outPath; }
bool VideoFile::isProcessed() { return processedStatus; }
	
void VideoFile::process() {
	callHandBrakeCLI();
	processedStatus = true; 
}

//I know system calls are evil, will move to ShellExecute/CreateProcess when I figure out how to make it work with HandBrakeCLI
void VideoFile::callHandBrakeCLI() {
		
		//Generates the encode flags to be used by ShellExecute
		string Flags = HandBrakeLocation.string() + inPath.string() + "\" -o \"" + outPath.string() + "\" " + flags;
		const char* formattedFlags = Flags.c_str();
		
		cout << formattedFlags << endl;

		system(formattedFlags);
		
	}
