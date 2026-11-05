// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_native_content_load_08181d6e956245b9.cpp

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
    bool operator==(const ContentId& other) const {return id.toString()==other.toString();}
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

std::string nativeFindAsset(ContentId); // 00560460 cdecl string return/byvalue32B
std::string nativeFindHashFile(ContentId); // 0055fdc0 sameABI
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
    bool isUrlBad(const char*);
    CachedContentRecord* loadContent(ContentId, int mode, const RequestCallback* callback);
};
CachedContentRecord* RequestProcessorView::loadContent(ContentId id, int mode, const RequestCallback* callback) {
    if (id.isNull()) return NULL;
    {
        boost::mutex::scoped_lock lock(contentCacheMutex());
        std::map<ContentId,CachedContentRecord>::iterator found = contentCache().find(id);
        if (found != contentCache().end()) return &found->second;
    }
    if (id.isAsset()) {
        boost::shared_ptr<const std::string> filename(new std::string(nativeFindAsset(id)));
        if (filename->empty()) return NULL;
        boost::mutex::scoped_lock lock(contentCacheMutex());
        CachedContentRecord& content = contentCache()[id];
        content.filename = filename;
        return &content;
    } else {
        boost::shared_ptr<const std::string> filename(new std::string(nativeFindHashFile(id)));
        if (!filename->empty()) {
            boost::mutex::scoped_lock lock(contentCacheMutex());
            CachedContentRecord& content = contentCache()[id];
            content.filename = filename;
            return &content;
        }
    }
    if (id.isHttp()) {
        switch(mode) {
        case 1: {
            boost::mutex::scoped_lock lock(requestSync());
            if (!isUrlBad(id.c_str())) {
                std::list<ContentRequest>::iterator found = std::find(requestQueue().begin(),requestQueue().end(),id);
                if (found == requestQueue().end()) {
                    requestQueue().push_back(ContentRequest());
                    ContentRequest& request = requestQueue().back();
                    request.id = id;
                    if (callback) request.callbacks.push_back(*callback);
                } else if (callback) {
                    found->callbacks.push_back(*callback);
                }
            }
            at<worker_thread*>(0x198)->wake();
            break;
        }
        case 2: {
            boost::shared_ptr<std::string> text(new std::string);
            try {
                Http(id.toString()).get(*text);
            } catch (std::exception&) {
                boost::mutex::scoped_lock lock(requestSync());
                {
                    FailedUrlRecord failed(id.c_str());
                    failedUrls().push_front(failed);
                }
                throw;
            }
            boost::mutex::scoped_lock lock(contentCacheMutex());
            CachedContentRecord& content = contentCache()[id];
            content.data = text;
            return &content;
        }
        }
    }
    return NULL;
}
}
