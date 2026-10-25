// Rebuild glue: ContentProvider and FileSystem members rbxgs declares and calls but never defines.
// Behavioural reconstruction, not byte-verified. getCacheDirectory follows the 2008 mining unit
// roc_cache_directory_native_family (CommonAppData\Roblox\Cache); the low-integrity (Vista protected
// mode) Temporary Internet Files branch is omitted.
#include "util/ContentProvider.h"
#include "util/FileSystem.h"
#include "util/Http.h"
#include <windows.h>
#include <shlobj.h>
#include <fstream>
#include <sstream>

namespace RBX
{
	std::string FileSystem::getCacheDirectory(bool create)
	{
		char path[MAX_PATH];
		HRESULT result = SHGetFolderPathAndSubDirA(NULL, CSIDL_COMMON_APPDATA | (create ? CSIDL_FLAG_CREATE : 0), NULL,
												   SHGFP_TYPE_CURRENT, "Roblox\\Cache", path);
		return result == S_OK ? path : "";
	}

	// Cached content, else load it: local files and assets synchronously; http on request type
	// (none: miss, async: queue for the worker thread, sync: fetch now). Failed urls are remembered.
	ContentProvider::CachedContent* ContentProvider::loadContent(ContentId id, HttpRequestType requestType)
	{
		{
			boost::mutex::scoped_lock lock(contentCacheMutex);
			std::map<ContentId, CachedContent>::iterator iter = contentCache.find(id);
			if (iter != contentCache.end())
				return &iter->second;
		}

		if (id.isNull())
			return NULL;

		CachedContent content;
		if (id.isHttp())
		{
			if (requestType == NoHttpRequest || isUrlBad(id.c_str()))
				return NULL;

			if (requestType == AsyncHttpRequest)
			{
				{
					boost::mutex::scoped_lock lock(requestSync);
					if (std::find(requestQueue.begin(), requestQueue.end(), id) == requestQueue.end())
						requestQueue.push_back(id);
				}
				requestProcessor->wake();
				return NULL;
			}

			std::string data;
			try
			{
				Http(id.toString()).get(data);
			}
			catch (std::exception&)
			{
				boost::mutex::scoped_lock lock(requestSync);
				failedUrls.push_back(FailedUrl(id.c_str()));
				return NULL;
			}
			content.data.reset(new std::string(data));
		}
		else
		{
			std::string file = id.isAsset() ? findAsset(id) : id.isFile() ? findFile(id) : findHashFile(id);
			if (file.empty())
				return NULL;
			content.filename.reset(new std::string(file));
		}

		boost::mutex::scoped_lock lock(contentCacheMutex);
		return &(contentCache[id] = content);
	}

	// one queued http request per call; the worker keeps calling while more are queued
	worker_thread::work_result ContentProvider::processRequests()
	{
		ContentId id;
		{
			boost::mutex::scoped_lock lock(requestSync);
			if (requestQueue.empty())
				return worker_thread::done;
			id = requestQueue.front();
			requestQueue.pop_front();
		}

		loadContent(id, SyncHttpRequest);

		boost::mutex::scoped_lock lock(requestSync);
		return requestQueue.empty() ? worker_thread::done : worker_thread::more;
	}

	std::auto_ptr<std::istream> ContentProvider::getContent(ContentId id)
	{
		CachedContent* content = loadContent(id, SyncHttpRequest);
		if (!content)
			throw std::runtime_error("Unable to load " + id.toString());

		if (content->data)
			return std::auto_ptr<std::istream>(new std::istringstream(*content->data, std::ios::in | std::ios::binary));

		std::auto_ptr<std::istream> stream(new std::ifstream(content->filename->c_str(), std::ios::in | std::ios::binary));
		if (!*stream)
			throw std::runtime_error("Unable to open " + *content->filename);
		return stream;
	}
}
