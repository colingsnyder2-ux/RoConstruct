// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /I{headers}/mfc-noinline-pcxstr /I{headers}/std-noinline-string /I{headers}/../../../tools/libs/mfc-9.0-rtm/atlmfc/include
// Recovered from OpenRBX ErrorUploader, inactive pending provider and ABI proof.
#include "ErrorUploaderState.h"
#include <algorithm>
#include "util/Http.h"
#include "util/standardout.h"
#include <fstream>
#include <sstream>

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

RBX::worker_thread::work_result ErrorUploader::upload(boost::shared_ptr<data> state)
{
	std::string file;
	{
		boost::recursive_mutex::scoped_lock lock(state->sync);
		if (state->files.empty()) {
			return RBX::worker_thread::done;
		}
		file = state->files.front();
	}

	try {
		std::string url = state->url;
		url += "?filename=";
		url += file;

		std::fstream data(file.c_str(), std::ios_base::in | std::ios_base::binary);
		unsigned int begin = data.tellg();
		data.seekg(0, std::ios_base::end);
		unsigned int end = data.tellg();
		if (end > begin) {
			data.seekg(0, std::ios_base::beg);
			std::string response;
			RBX::Http(url).post(data, true, response);
		}
		else {
			std::stringstream data("Empty!!!");
			std::string response;
			RBX::Http(url).post(data, true, response);
		}
	}
	catch (std::exception& e) {
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, e);
	}

	{
		boost::recursive_mutex::scoped_lock lock(state->sync);
		state->files.pop();
	}

	return RBX::worker_thread::more;
}
