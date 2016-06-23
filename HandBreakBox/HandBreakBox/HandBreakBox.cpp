// HandBreakBox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HandBreakBox.h"
#include<iostream>
using namespace std;
using namespace boost::filesystem;


int main() {
	path syncFolderPath = path("C:\\vidTest");
	path outputFolderPath = path("C:\\vidTest\\Test");
	FileManager fm(syncFolderPath, outputFolderPath);
	fm.getFileList();
	fm.printFileList();
	cin.get();
}