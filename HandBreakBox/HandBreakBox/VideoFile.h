#pragma once
#include<boost/filesystem.hpp>
#include<string>

using namespace std;
using namespace boost::filesystem;

class VideoFile {

public:
	VideoFile(path otherIn, path otherOut, string flags = "--preset = \"Normal\"");

	path getInPath() const;
	path getOutPath() const;
	bool isProcessed();

	void process();

private:
	void callHandBrakeCLI(path, path, string);

	path inPath;
	path outPath;
	string flags;
	bool processedStatus;
};