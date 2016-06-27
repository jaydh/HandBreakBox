#pragma once

#include<vector>
#include<boost/chrono.hpp>
#include<Filemanager.h>
#include<boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>

using namespace std;
using namespace boost::chrono;

class ScheduleManager {
public:
	ScheduleManager(boost::asio::io_service & io, FileManager & fm, long interval = 10);
	void updateFileManager();
	void manageUpdates(const boost::system::error_code &);
	void addAvailableTime();
	void checkForOverlap();

private:
	FileManager fm;
	long syncInterval;
	boost::asio::io_service io;
	boost::asio::deadline_timer t;
};