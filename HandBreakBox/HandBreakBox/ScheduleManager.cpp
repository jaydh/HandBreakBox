#include<ScheduleManager.h>

ScheduleManager::ScheduleManager(boost::asio::io_service& io, FileManager& fm, long interval) : fm(fm), t(io, boost::posix_time::seconds(interval)), syncInterval(interval) {
	fm.updateFileList();
	fm.printFileList(cout);
	t.async_wait(boost::bind(&ScheduleManager::updateFileManager, this));
	fm.processFiles();
}

void ScheduleManager::updateFileManager(){
	fm.updateFileList();

	//Reset timer
	t.expires_at(t.expires_at() + boost::posix_time::seconds(syncInterval));
	t.async_wait(boost::bind(&ScheduleManager::updateFileManager, this));
}

void ScheduleManager::addAvailableTime() { }

void ScheduleManager::checkForOverlap()
{
}
