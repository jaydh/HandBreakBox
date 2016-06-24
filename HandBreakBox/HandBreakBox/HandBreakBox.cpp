// HandBreakBox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HandBreakBox.h"
using namespace std;
using namespace boost::filesystem;


int main() {
	path syncFolderPath = path("E:\\Videos\\Anime\\Re Zero");
	path outputFolderPath = path("E:\\Videos\\Anime\\Re Zero\\Test");
	FileManager fm(syncFolderPath, outputFolderPath);

	fm.getFileList();
	fm.printFileList(cout);
	fm.processFiles();
	cin.get();
}