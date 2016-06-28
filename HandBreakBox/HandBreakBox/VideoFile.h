#pragma once
#include<boost/filesystem.hpp>
#include<boost/chrono.hpp>

using namespace std;
using namespace boost::filesystem;

class VideoFile {

public:
	VideoFile(path other);

	void setPath(path const& other) { filePath = other; }
	path getPath() const { return filePath; }
	uintmax_t getInFileSize() const { return inFileSize; }
	friend bool operator<(VideoFile a, VideoFile b) { return a.getInFileSize() > b.getInFileSize();	}

private:
	path filePath;
	uintmax_t inFileSize;
	bool processedStatus;
};