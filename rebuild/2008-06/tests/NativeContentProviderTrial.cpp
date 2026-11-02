// Isolated layout/lifetime trial; donor ContentProvider is a different singleton class.
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
extern const char* sContentProvider;
enum RequestResult { Waiting, Succeeded, Failed };
typedef boost::function<void(RequestResult, std::istream&)> RequestCallback;
struct ContentRequest {
    ContentId id;
    std::vector<RequestCallback> callbacks;
    bool operator==(const ContentId& other) const { return id.toString() == other.toString(); }
};
class ContentProvider : public DescribedNonCreatable<ContentProvider, Instance, &sContentProvider> {
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
    bool isUrlBad(const char*);
    static bool isUrl(const std::string&);
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
namespace RBX {
#ifndef NATIVE_CONTENT_PROVIDER_TYPES_ONLY
template<> Reflection::ClassDescriptor& Reflection::Described<ContentProvider, &sContentProvider,
    NonFactoryProduct<Instance, &sContentProvider> >::classDescriptor() {
    static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), "ContentProvider");
    return descriptor;
}
ContentProvider::ContentProvider()
{
    requestProcessor.reset(new worker_thread(boost::bind(&ContentProvider::processRequests, this), "rbx_content"));
}
ContentProvider::~ContentProvider()
{
    requestProcessor->join();
}
#endif
}
