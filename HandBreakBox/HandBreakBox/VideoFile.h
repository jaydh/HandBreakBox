#pragma once
#include<boost/filesystem.hpp>
#include<boost/chrono.hpp>

using namespace std;
using namespace boost::filesystem;

class VideoFile {

public:
	VideoFile(path otherIn, path otherOut, string flags = "");

	void setInPath(path const& otherIn);
	void setOutPath(path const& otherOut);
	void setFlags(string const& otherFlags);
	path getInPath() const;
	path getOutPath() const;
	bool isProcessed();

	void process();

private:
	void callHandBrakeCLI();

	path inPath;
	path outPath;
	string flags;
	bool processedStatus;
};