// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_content_request_named_4069813f13588a7f.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include "util/ContentProvider.h"
#include "util/Http.h"
#include "util/StandardOut.h"
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

namespace RBX {
// Status values are independently visible in the 2008 caller (1/2).
// The 2016 AsyncHttpQueue names corroborate their meaning.
enum RequestResult { Waiting, Succeeded, Failed };
typedef boost::function<void(RequestResult, std::istream&)> RequestCallback;
struct ContentRequest {
    ContentId id;
    std::vector<RequestCallback> callbacks;
};
void readContent(RequestCallback, RequestResult, boost::shared_ptr<const std::string>);

// Native 2007 cache/failed-URL records. Only the owning class revision differs.
struct CachedContentRecord {
    boost::shared_ptr<const std::string> data;
    boost::shared_ptr<const std::string> filename;
};
struct FailedUrlRecord {
    std::string url;
    boost::posix_time::ptime expiration;
    FailedUrlRecord(const char*);
};

class RequestProcessorView {
    template<class T> T& at(unsigned offset) {
        return *reinterpret_cast<T*>(reinterpret_cast<char*>(this) + offset);
    }
    boost::mutex& requestSync() { return at<boost::mutex>(0x130); }
    std::list<ContentRequest>& requestQueue() { return at<std::list<ContentRequest> >(0x138); }
    std::list<FailedUrlRecord>& failedUrls() { return at<std::list<FailedUrlRecord> >(0x154); }
    boost::mutex& contentCacheMutex() { return at<boost::mutex>(0x170); }
    std::map<ContentId, CachedContentRecord>& contentCache() {
        return at<std::map<ContentId, CachedContentRecord> >(0x178);
    }
public:
    int processRequests();
};
int RequestProcessorView::processRequests() {
    ContentRequest request;
    {
        boost::mutex::scoped_lock lock(requestSync());
        if (requestQueue().empty()) return 0;
        request = requestQueue().front();
    }
    boost::shared_ptr<std::string> text(new std::string);
    RequestResult result;
    try {
        try {
            Http(request.id.toString()).get(*text);
            result = Succeeded;
        } catch (std::exception&) {
            result = Failed;
            boost::mutex::scoped_lock lock(requestSync());
            {
                FailedUrlRecord failed(request.id.c_str());
                failedUrls().push_front(failed);
            }
            throw;
        }
        boost::mutex::scoped_lock lock(contentCacheMutex());
        contentCache()[request.id].data = text;
    } catch (std::exception& e) {
        StandardOut::singleton()->print(MESSAGE_ERROR, "Content failed for %s because %s", request.id.c_str(), e.what());
    }
    std::for_each(request.callbacks.begin(), request.callbacks.end(), boost::bind(&readContent, _1, result, text));
    {
        boost::mutex::scoped_lock lock(requestSync());
        requestQueue().erase(requestQueue().begin());
    }
    return 1;
}
typedef char CheckCallbackSize[sizeof(RequestCallback) == 32 ? 1 : -1];
typedef char CheckRequestSize[sizeof(ContentRequest) == 56 ? 1 : -1];
typedef char CheckHttpSize[sizeof(Http) == 56 ? 1 : -1];
}
