#include<ScheduleManager.h>

ScheduleManager::ScheduleManager(path in, path out, boost::asio::io_service& io, long interval) : fm(in, out), t(io, boost::posix_time::seconds(interval)), syncInterval(interval) {
	fm.updateFileList();
	fm.printFileList(cout);
	t.async_wait(boost::bind(&ScheduleManager::updateFileManager, this));
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
