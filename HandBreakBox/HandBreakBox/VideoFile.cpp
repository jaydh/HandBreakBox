#include<Boost/filesystem.hpp>
#include<Windows.h>
#include<shellapi.h>
#include<string>

using namespace std;
using namespace boost::filesystem;

//include output directory 

class VideoFile {

public:
	VideoFile(path otherIn, path otherOut, string flags) :inPath(otherIn), outPath(otherOut), flags(flags) {
		//if (otherIn == nullptr) { throw invalid_argument; }
		processedStatus = false;
	}

	path getInPath() const { return inPath; }
	path getOutPath() const { return outPath; }
	bool isProcessed() { return processedStatus; }
	
	void process() {
		callHandBrakeCLI(inPath, outPath, flags);
		processedStatus = true; 
	}
	
private:
	path inPath;
	path outPath;
	string flags;
	bool processedStatus;

	//Uses ShellEecuteEx to call HandbrakeCLI with relevant flags
	void callHandBrakeCLI(path inFile, path outFile, string flags) {
		
		//Generates the encode flags to be used by ShellExecute
		const string formattedFlags = "-i " + inFile.string() + "-o " + outFile.string() + " " + flags;
		std::wstring stemp = std::wstring(formattedFlags.begin(), formattedFlags.end());
		LPCWSTR flag = stemp.c_str();

		SHELLEXECUTEINFO ShExecInfo = { 0 };
		ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		ShExecInfo.hwnd = NULL;
		ShExecInfo.lpVerb = NULL;
		ShExecInfo.lpFile = TEXT("C:\\Users\\jay\\Desktop\\HandBrakeCLI.exe";)
		ShExecInfo.lpParameters = flag;
		ShExecInfo.lpDirectory = NULL;
		ShExecInfo.nShow = SW_SHOW;
		ShExecInfo.hInstApp = NULL;
		ShellExecuteEx(&ShExecInfo);
		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
		
	}
};