#pragma once

#include "resource.h"
#include<Boost/filesystem.hpp>
#include<queue>
using namespace std;
using namespace boost::filesystem;

queue<path> getFileList(const path&);

int main();