// Isolated layout/lifetime trial; donor ContentProvider is a different singleton class.
// >>> native-status (generated) -- do not edit >>>
// ContentProvider | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src d3e00db6 | roc native-status --write
#include "util/NativeContentProvider.h"
#include "util/Http.h"
#include "util/standardout.h"
#include <algorithm>

namespace RBX {
#ifndef NATIVE_CONTENT_PROVIDER_TYPES_ONLY
void readContent(RequestCallback, RequestResult, boost::shared_ptr<const std::string>);
worker_thread::work_result ContentProvider::processRequests()
{
    ContentRequest request;
    {
        boost::mutex::scoped_lock lock(requestSync);
        if (requestQueue.empty()) return worker_thread::done;
        request = requestQueue.front();
    }
    boost::shared_ptr<std::string> text(new std::string);
    RequestResult result;
    try {
        try {
            Http(request.id.toString()).get(*text);
            result = Succeeded;
        } catch (std::exception&) {
            result = Failed;
            boost::mutex::scoped_lock lock(requestSync);
            {
                FailedUrl failed(request.id.c_str());
                failedUrls.push_front(failed);
            }
            throw;
        }
        boost::mutex::scoped_lock lock(contentCacheMutex);
        contentCache[request.id].data = text;
    } catch (std::exception& error) {
        StandardOut::singleton()->print(MESSAGE_ERROR, "Content failed for %s because %s", request.id.c_str(), error.what());
    }
    std::for_each(request.callbacks.begin(), request.callbacks.end(), boost::bind(&readContent, _1, result, text));
    {
        boost::mutex::scoped_lock lock(requestSync);
        requestQueue.erase(requestQueue.begin());
    }
    return worker_thread::more;
}
template<> Reflection::ClassDescriptor& Reflection::Described<ContentProvider, sContentProvider,
    NonFactoryProduct<Instance, sContentProvider> >::classDescriptor() {
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
