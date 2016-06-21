#include<Boost/filesystem.hpp>
#include<Windows.h>
#include<shellapi.h>
#include<string>

using namespace std;
using namespace boost::filesystem;

//include output directory 

class VideoFile {

public:
	VideoFile(path other) :inPath{ other } {
		
		processedStatus = false;
	}
	path getInPath() const { return inPath; }
	path getOutPath() const { return outPath; }
	bool isProcessed() { return processedStatus; }
	
	void process() { 
		processedStatus = true; 
	}
	
private:
	path inPath;
	path outPath;
	bool processedStatus;

	void callHandBrakeCLI(string inFile, string outFile = "%HOMEPATH%\\Videos", string flags = "--preset = \"Normal\"") {
		
		//Generates the encode flags to be used by ShellExecute
		const string formattedFlags = "-i " + inFile + "-o " + outFile + " " + flags;
		std::wstring stemp = std::wstring(formattedFlags.begin(), formattedFlags.end());
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
};