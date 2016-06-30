#pragma once
#include<boost/filesystem.hpp>
#include<boost/chrono.hpp>
#include<boost/unordered_set.hpp>

using namespace std;
using namespace boost::filesystem;

bool operator==(path const& p1, path const& p2)
{
	return p1.string() == p2.string() && file_size(p1) == file_size(p2);
}

struct path_hash
	: std::unary_function<path, std::size_t>
{
	std::size_t operator()(path const& p) const
	{
		return size_t(file_size(p));
	}
};

class VideoFile {

public:
	VideoFile(path otherIn, path otherOut);
	~VideoFile();
	
	void setInPath(path const& other) { inPath = other; }
	void setOutPath(path const& other) { outPath = other; }
	void setProcssedStatus(const bool other) { processedStatus = true; }
	path getInPath() const { return inPath; }
	path getOutPath() const { return outPath; }
	bool getProcessedStatus() const { return processedStatus; }
	uintmax_t getInFileSize() const { return inFileSize; }

	friend bool operator<(VideoFile a, VideoFile b) { return a.getInFileSize() > b.getInFileSize();	}
	static boost::unordered_set<path, path_hash> inputPaths;
private:
	path inPath;
	path outPath;
	uintmax_t inFileSize;
	bool processedStatus;
};