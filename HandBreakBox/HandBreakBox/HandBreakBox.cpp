// HandBreakBox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HandBreakBox.h"
#include<string>
#include<Windows.h>
#include<shellapi.h>
#include<Boost/filesystem.hpp>
#include<Boost/optional.hpp>
#include<queue>
#include<unordered_set>
#include<string>


const static std::unordered_set<std::string> videoFileExtensions {".mkv", ".mp4" };

using namespace boost::filesystem;
void getFileList(const path& dirPath, std::queue<path> & videoFiles) {
	recursive_directory_iterator dir(dirPath), end;
	for (; dir != end; dir++) {
		if (videoFileExtensions.count(dir->path.exention())) {
			videoFiles.push(dir->path);
		}
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

int main() {
	queue<path> filesToConvert;
}