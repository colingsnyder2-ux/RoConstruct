#pragma once
#include "CRobloxApp.h"
#include <queue>
#include <boost/thread/recursive_mutex.hpp>

struct ErrorUploader::data {
    std::queue<std::string> files;
    boost::recursive_mutex sync;
    std::string url;
    data();
    static RBX::worker_thread::work_result uploadNext(boost::shared_ptr<data> state);
};

inline bool ErrorUploader::IsUploading()
{
    return !state->files.empty();
}
