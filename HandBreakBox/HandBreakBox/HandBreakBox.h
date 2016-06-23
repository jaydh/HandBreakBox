#pragma once

#include "resource.h"
#include<VideoFile.h>
#include<boost/filesystem.hpp>
#include<queue>
using namespace std;
using namespace boost::filesystem;

queue<path> getFileList(const path &dirPath);

int main();