#include<ScheduleManager.h>

typedef boost::posix_time::seconds timeUnit;

ScheduleManager::ScheduleManager(boost::asio::io_service& io, FileManager& fm, long interval) : fm(fm), t(io, timeUnit(interval)), syncInterval(interval) {
	
	fm.updateFileList();
	cout << "Number of VideoFiles: " << fm.getVideoFileCount() << endl;
	t.async_wait(boost::bind(&ScheduleManager::updateFileManager, this));
}

void ScheduleManager::updateFileManager(){

	fm.updateFileList();

	//Reset timer
	t.expires_at(t.expires_at() + timeUnit(syncInterval));
	t.async_wait(boost::bind(&ScheduleManager::updateFileManager, this));
}

void ScheduleManager::addAvailableTime() { }

void ScheduleManager::checkForOverlap()
{
}
