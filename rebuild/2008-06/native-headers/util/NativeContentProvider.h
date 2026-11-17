#pragma once
#include "util/ContentRequest.h"

#define ContentProvider DonorContentProvider
#include "util/ContentProvider.h"
#undef ContentProvider
#include "v8tree/Instance.h"
#include <boost/bind.hpp>
#include <boost/scoped_ptr.hpp>
#include <cstddef>
#include <list>
#include <map>

namespace RBX {
extern char sContentProvider[];
struct ContentRequest {
    ContentId id;
    std::vector<RequestCallback> callbacks;
    bool operator==(const ContentId& other) const { return id.toString() == other.toString(); }
public:
	ContentRequest(RBX::ContentRequest const &);   // INFERRED: ??0ContentRequest@RBX@@QAE@ABU01@@Z (header gap, header_gap_fill.py)
public:
	ContentRequest(void);   // INFERRED: ??0ContentRequest@RBX@@QAE@XZ (header gap, header_gap_fill.py)
public:
	~ContentRequest(void);   // INFERRED: ??1ContentRequest@RBX@@QAE@XZ (header gap, header_gap_fill.py)
};
class ContentProvider : public DescribedNonCreatable<ContentProvider, Instance, sContentProvider> {
public:
    struct FailedUrl {
        std::string url;
        boost::posix_time::ptime expiration;
        FailedUrl(const char*);
    };
    struct CachedContent {
        boost::shared_ptr<const std::string> data;
        boost::shared_ptr<const std::string> filename;
    };
    boost::mutex requestSync;
    std::list<ContentRequest> requestQueue;
    std::list<FailedUrl> failedUrls;
    boost::mutex contentCacheMutex;
    std::map<ContentId, CachedContent> contentCache;
    boost::scoped_ptr<worker_thread> requestProcessor;
    ContentProvider();
    virtual ~ContentProvider();
    worker_thread::work_result processRequests();
    std::auto_ptr<std::istream> getContent(ContentId);
    CachedContent* loadContent(ContentId, int, const RequestCallback*);
    std::string getFile(ContentId);
    bool isUrlBad(const char*);
    static bool isUrl(const std::string&);
private:
    bool registerFile(CachedContent*);
public:
	void load(RBX::ContentId,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > &);   // INFERRED: ?load@ContentProvider@RBX@@QAEXVContentId@2@AAV?$vector@V?$shared_ptr@VInstance@RBX@@@boost@@V?$allocator@V?$shared_ptr@VInstance@RBX@@@boost@@@std@@@std@@@Z (header gap, header_gap_fill.py)
	public:
		void sub_00562530(const ContentId& id, boost::function<void(RequestResult, std::istream&)> callback);   // INFERRED: 00562530, placeholder name (identity tier), body byte-proved (Inferred_00562530.cpp)
};
typedef char ProviderSize[sizeof(ContentProvider) == 0x19c ? 1 : -1];
typedef char ProviderRequestSize[sizeof(ContentRequest) == 0x38 ? 1 : -1];
typedef char ProviderRequestMutex[offsetof(ContentProvider, requestSync) == 0x130 ? 1 : -1];
typedef char ProviderRequestQueue[offsetof(ContentProvider, requestQueue) == 0x138 ? 1 : -1];
typedef char ProviderFailedUrls[offsetof(ContentProvider, failedUrls) == 0x154 ? 1 : -1];
typedef char ProviderCacheMutex[offsetof(ContentProvider, contentCacheMutex) == 0x170 ? 1 : -1];
typedef char ProviderCache[offsetof(ContentProvider, contentCache) == 0x178 ? 1 : -1];
typedef char ProviderWorker[offsetof(ContentProvider, requestProcessor) == 0x198 ? 1 : -1];
}

typedef boost::_bi::bind_t<RBX::worker_thread::work_result,
    boost::_mfi::mf0<RBX::worker_thread::work_result, RBX::ContentProvider>,
    boost::_bi::list1<boost::_bi::value<RBX::ContentProvider*> > > ContentProviderBind;
namespace boost {
template<> template<> function0<RBX::worker_thread::work_result, std::allocator<boost::function_base> >::function0(ContentProviderBind, int) throw();
}
