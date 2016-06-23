#include<boost/filesystem.hpp>
#include<Windows.h>
#include<shellapi.h>
#include<string>
#include<VideoFile.h>
#include<iostream>
using namespace std;
using namespace boost::filesystem;


VideoFile::VideoFile(path otherIn, path otherOut, string flags) :inPath(otherIn), outPath(otherOut), flags(flags) {
	//if (otherIn == nullptr) { throw invalid_argument; }
	processedStatus = false;
}

path VideoFile::getInPath() const { return inPath; }
path VideoFile::getOutPath() const { return outPath; }
bool VideoFile::isProcessed() { return processedStatus; }
	
void VideoFile::process() {
	callHandBrakeCLI(inPath, outPath, flags);
	processedStatus = true; 
}

//Uses ShellEecuteEx to call HandbrakeCLI with relevant flags
void VideoFile::callHandBrakeCLI(path inFile, path outFile, string flags) {
		
		//Generates the encode flags to be used by ShellExecute
		string formattedFlags = " C/ C:\\Users\\jay\\Desktop\\HandBrakeCLI.exe -i " + inFile.string() + "-o " + outFile.string() + " " + flags;
		std::wstring stemp = std::wstring(formattedFlags.begin(), formattedFlags.end());
		cout << stemp << endl;
		LPCWSTR flag = stemp.c_str();
		cout << flag << endl;

		ShellExecute(
			NULL
			, TEXT("open")
			, TEXT("cmd")
			, flag
			, NULL
			,
			SW_SHOW);
		
	}
