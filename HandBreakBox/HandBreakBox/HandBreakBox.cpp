// HandBreakBox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HandBreakBox.h"
#include<string>
#include<Windows.h>
#include<shellapi.h>
#include<boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include<iostream>


//recursively get files in main directory
//Add video file locations to queue
//Convert Files
//If queue is empty, move all files out.

using namespace boost::filesystem;
void getFileList(){
	if (is_directory(p)) {
		std::cout << p << " is a directory containing:\n";

		for (auto& entry : boost::make_iterator_range(directory_iterator(p), {}))
			std::cout << entry << "\n";
	}
}

using namespace std;
void callHandBrakeCLI(string inFile, string outFile = "%HOMEPATH%\\Videos", string flags = "--preset = \"Normal\"") {

	//Generates the encode flags to be used by ShellExecute
	const string flags = "-i " + inFile + "-o " + outFile + " " + flags;
	std::wstring stemp = std::wstring(flags.begin(), flags.end());
	LPCWSTR flag = stemp.c_str();

	SHELLEXECUTEINFO ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = TEXT("C:\\Users\\jayho\\OneDrive\\Documents\\HandBrakeCLI\\HandBrakeCLI.exe";)
	ShExecInfo.lpParameters = flag;
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_SHOW;
	ShExecInfo.hInstApp = NULL;
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
}
bool find_file(const path & dir_path,         // in this directory,
	const std::string & file_name, // search for this name,
	path & path_found)            // placing path here if found
{
	if (!exists(dir_path)) return false;
	directory_iterator end_itr; // default construction yields past-the-end
	for (directory_iterator itr(dir_path);
		itr != end_itr;
		++itr)
	{
		if (is_directory(itr->status()))
		{
			if (find_file(itr->path(), file_name, path_found)) return true;
		}
		else if (itr->leaf() == file_name) // see below
		{
			path_found = itr->path();
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	path p(argc>1 ? argv[1] : ".");

	
}