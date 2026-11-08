#include "util/boost.hpp"
typedef char checkWorkerSize[(sizeof(RBX::worker_thread) == 0x14) ? 1 : -1];
namespace RBX {
worker_thread::~worker_thread()
{
    boost::mutex::scoped_lock scoped_lock(_data->sync);
    _data->endRequest = true;
    _data->wakeCondition.notify_all();
}
}
