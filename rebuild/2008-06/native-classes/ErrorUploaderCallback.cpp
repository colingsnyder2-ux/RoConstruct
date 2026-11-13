// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-function-pod-vtable /I{headers}/std-noinline-string
// >>> native-status (generated) -- do not edit >>>
// ErrorUploaderCallback | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8d110cdf | roc native-status --write
#include "ErrorUploaderState.h"
#include "util/Http.h"
#include "util/standardout.h"
#include <fstream>
#include <sstream>

RBX::worker_thread::work_result ErrorUploader::upload(boost::shared_ptr<data> state)
{
    std::string filename;
    {
        boost::recursive_mutex::scoped_lock lock(state->sync);
        if (state->files.empty()) return RBX::worker_thread::done;
        filename = state->files.front();
    }
    try {
        std::string url = state->url;
        url += "?filename=";
        url += filename;
        std::fstream file(filename.c_str(), std::ios::in | std::ios::binary);
        unsigned int start = file.tellg();
        file.seekg(0, std::ios::end);
        unsigned int end = static_cast<unsigned int>(file.tellg());
        if (end > start) {
            file.seekg(0, std::ios::beg);
            std::string response;
            RBX::Http(url).post(file, true, response);
        } else {
            std::stringstream empty("Empty!!!");
            std::string response;
            RBX::Http(url).post(empty, true, response);
        }
    } catch (const std::exception& error) {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, error);
    }
    {
        boost::recursive_mutex::scoped_lock lock(state->sync);
        state->files.pop();
    }
    return RBX::worker_thread::more;
}
