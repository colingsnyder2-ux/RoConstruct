// Isolated layout/lifetime trial; donor ContentProvider is a different singleton class.
// >>> native-status (generated) -- do not edit >>>
// ContentProvider | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src bd5aed20 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::_bi::list1<boost::_bi::value<RBX::ContentProvider *> >;
template class boost::_bi::value<RBX::ContentProvider *>;
template class boost::_bi::value<boost::shared_ptr<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >;
template class boost::_bi::value<enum RBX::RequestResult>;
template class boost::function2<void,enum RBX::RequestResult,std::basic_istream<char,std::char_traits<char> > &,std::allocator<void> >;
template class boost::function<void __cdecl(enum RBX::RequestResult,std::basic_istream<char,std::char_traits<char> > &),std::allocator<void> >;
template class boost::shared_ptr<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::ContentProvider::FailedUrl> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::ContentRequest> >;
template class std::_Container_base_aux_alloc_real<std::allocator<boost::function<void __cdecl(enum RBX::RequestResult,std::basic_istream<char,std::char_traits<char> > &),std::allocator<void> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::ContentId const ,RBX::ContentProvider::CachedContent> > >;
template class std::_Tree<std::_Tmap_traits<RBX::ContentId,RBX::ContentProvider::CachedContent,std::less<RBX::ContentId>,std::allocator<std::pair<RBX::ContentId const ,RBX::ContentProvider::CachedContent> >,0> >;
template class std::_Vector_const_iterator<boost::function<void __cdecl(enum RBX::RequestResult,std::basic_istream<char,std::char_traits<char> > &),std::allocator<void> >,std::allocator<boost::function<void __cdecl(enum RBX::RequestResult,std::basic_istream<char,std::char_traits<char> > &),std::allocator<void> > > >;
template class std::_Vector_iterator<boost::function<void __cdecl(enum RBX::RequestResult,std::basic_istream<char,std::char_traits<char> > &),std::allocator<void> >,std::allocator<boost::function<void __cdecl(enum RBX::RequestResult,std::basic_istream<char,std::char_traits<char> > &),std::allocator<void> > > >;
template class std::allocator<RBX::ContentProvider::FailedUrl>;
template class std::allocator<RBX::ContentRequest>;
template class std::allocator<std::_List_nod<RBX::ContentProvider::FailedUrl,std::allocator<RBX::ContentProvider::FailedUrl> >::_Node *>;
template class std::allocator<std::_List_nod<RBX::ContentRequest,std::allocator<RBX::ContentRequest> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::ContentId,RBX::ContentProvider::CachedContent,std::less<RBX::ContentId>,std::allocator<std::pair<RBX::ContentId const ,RBX::ContentProvider::CachedContent> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::ContentId const ,RBX::ContentProvider::CachedContent> >;
template class std::vector<boost::function<void __cdecl(enum RBX::RequestResult,std::basic_istream<char,std::char_traits<char> > &),std::allocator<void> >,std::allocator<boost::function<void __cdecl(enum RBX::RequestResult,std::basic_istream<char,std::char_traits<char> > &),std::allocator<void> > > >;
