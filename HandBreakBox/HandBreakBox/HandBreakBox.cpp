// HandBreakBox.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "HandBreakBox.h"
using namespace std;
using namespace boost::filesystem;

int main() {

	/*HWND window;
	AllocConsole();
	window = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(window, 0);
	*/
	string inputFolder;
	string outputFolder;
	cout << "Enter input folder path:";
	getline(cin, inputFolder);
	cout << endl << "Enter output folder path:";
	getline(cin, outputFolder);

	path syncFolderPath = path(inputFolder);
	path outputFolderPath = path(outputFolder);
	boost::asio::io_service io;
	FileManager fm(syncFolderPath, outputFolderPath);
	ScheduleManager sm(io, fm);
	io.run();
	
	cin.get();
}