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

	path syncFolderPath = path("C:\\vidTest");
	path outputFolderPath = path("C:\\vidTestOut");
	boost::asio::io_service io;
	ScheduleManager sm(syncFolderPath, outputFolderPath, io);
	io.run();
	
	cin.get();
}