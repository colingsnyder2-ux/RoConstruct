// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// Recovered from OpenRBX ErrorUploader, inactive pending provider and ABI proof.
#include "ErrorUploaderState.h"
#include <algorithm>

void ErrorUploader::Upload(std::string url, bool synchronous)
{
    std::vector<std::string> files = LogManager::getMainLogManger()->archiveCrashLogs();
    {
        boost::recursive_mutex::scoped_lock lock(state->sync);
        state->url = url;
        for (unsigned int i = std::max<int>(0, files.size() - 12); i < files.size(); ++i)
            state->files.push(files[i]);
    }
    if (!synchronous)
        thread.wake();
    else
        while (upload(state) != RBX::worker_thread::done) {}
}
