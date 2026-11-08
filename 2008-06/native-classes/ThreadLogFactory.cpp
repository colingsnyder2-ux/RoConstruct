// >>> native-status (generated) -- do not edit >>>
// ThreadLogFactory | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 1812bccd | roc native-status --write
#include "CRobloxApp.h"
#include <boost/thread/once.hpp>
#include <boost/thread/tss.hpp>

const char* currentThreadName();

LogManager::LogManager(const char* label)
    : log(0), threadId(GetCurrentThreadId()), name(label)
{
}

ThreadLogManager::ThreadLogManager() : LogManager(currentThreadName())
{
}

namespace {
boost::thread_specific_ptr<ThreadLogManager>* threadLogs;
boost::once_flag threadLogsOnce = BOOST_ONCE_INIT;

void initializeThreadLogs()
{
    static boost::thread_specific_ptr<ThreadLogManager> storage;
    threadLogs = &storage;
}
}

ThreadLogManager* currentThreadLogManager()
{
    boost::call_once(initializeThreadLogs, threadLogsOnce);
    ThreadLogManager* manager = threadLogs->get();
    if (!manager) {
        manager = new ThreadLogManager;
        threadLogs->reset(manager);
    }
    return manager;
}
