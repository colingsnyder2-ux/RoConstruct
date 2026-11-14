#pragma once
// >>> native-status (generated) -- do not edit >>>
// ErrorUploaderState | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 317f2f34 | roc native-status --write
#include "CRobloxApp.h"
#include <queue>
#include <boost/thread/recursive_mutex.hpp>

struct ErrorUploader::data {
    std::queue<std::string> files;
    boost::recursive_mutex sync;
    std::string url;
    data();
};

inline bool ErrorUploader::IsUploading()
{
    return !state->files.empty();
}
