#pragma once
#include<boost/filesystem.hpp>
#include<string>

using namespace std;
using namespace boost::filesystem;

class VideoFile {

public:
	VideoFile(path, path, string flags = "--preset = \"Normal\"");
	path getInPath() const;
	path getOutPath() const;
	bool isProcessed();

	void process();

private:
	path inPath;
	path outPath;
	bool processedStatus;

	void callHandBrakeCLI(path, path, string);
};