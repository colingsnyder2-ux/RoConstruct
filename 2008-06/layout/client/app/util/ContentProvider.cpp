// INFERRED: RBX::ContentProvider::sub_00562730 (placeholder name for 00562730 from the identity tier; body from assembly)
#include "util/NativeContentProvider.h"
#include <fstream>
#include <sstream>

namespace RBX {
// INFERRED: 0055f4f0 is an out-of-line stream copy helper (istream, ostream, chunk size); a boost iostreams copy, not recovered here
void __cdecl copyStream(std::istream& in, std::ostream& out, int chunk);

boost::shared_ptr<const std::string> ContentProvider::sub_00562730(const ContentId& id)
{
    CachedContent* content = loadContent(id, 1, NULL);
    if (!content)
        return boost::shared_ptr<const std::string>();
    boost::mutex::scoped_lock lock(contentCacheMutex);
    if (!content->data) {
        std::ifstream file(content->filename->c_str(), std::ios::in | std::ios::binary, _SH_DENYNO);
        std::ostringstream data(std::ios::out);
        copyStream(file, data, 0x1000);
        content->data.reset(new std::string(data.str()));
    }
    return content->data;
}
}

#include "util/Name.h"

namespace RBX {

bool ContentProvider::hasContent(ContentId id)
{
	return loadContent(id, 0, 0) != 0;
}

}

namespace RBX {
ContentId ContentId::fromAssets(const char* path) {
 std::string prefix("rbxasset://");
 return ContentId(prefix + path);
}
}

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
    ::RBX::RequestResult result;
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

namespace RBX {
ContentProvider::FailedUrl::FailedUrl(const char* value)
    : url(value), expiration(boost::posix_time::second_clock::local_time() + boost::posix_time::minutes(5))
{
}

bool ContentProvider::isUrlBad(const char* url)
{
    boost::mutex::scoped_lock lock(requestSync);
    std::list<FailedUrl>::iterator end = failedUrls.end();
    std::list<FailedUrl>::iterator iter = failedUrls.begin();
    for (; iter != end; iter++) {
        if (boost::posix_time::second_clock::local_time() >= iter->expiration) {
            failedUrls.erase(iter, end);
            return false;
        } else if (iter->url == url) {
            return true;
        }
    }
    return false;
}
}

template class boost::date_time::base_time<boost::posix_time::ptime,boost::date_time::counted_time_system<boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config> > >;
template class boost::date_time::counted_time_system<boost::date_time::counted_time_rep<boost::posix_time::millisec_posix_time_system_config> >;
template class boost::date_time::date<boost::gregorian::date,boost::gregorian::gregorian_calendar,boost::date_time::date_duration<boost::date_time::duration_traits_adapted> >;
template class boost::date_time::gregorian_calendar_base<boost::date_time::year_month_day_base<boost::gregorian::greg_year,boost::gregorian::greg_month,boost::gregorian::greg_day>,unsigned long>;
template class boost::date_time::int_adapter<__int64>;

#include <G3D/format.h>
#include <stdexcept>

namespace RBX {
std::auto_ptr<std::istream> ContentProvider::getContent(ContentId id)
{
    CachedContent* content = loadContent(id, 2, 0);
    if (!content)
        throw std::runtime_error(G3D::format("Unable to load %s", id.c_str()));
    if (content->data)
        return std::auto_ptr<std::istream>(new std::istringstream(*content->data, std::ios::in));
    return std::auto_ptr<std::istream>(new std::ifstream(content->filename->c_str(), std::ios::in | std::ios::binary));
}
}

namespace RBX {
std::string ContentProvider::getFile(ContentId ticket)
{
    CachedContent* content = loadContent(ticket, /* SyncHttpRequest */ 2, 0);
    if (content && registerFile(content))
        return *content->filename;
    throw std::runtime_error(G3D::format("Unable to load %s", ticket.c_str()));
}
}

#include "v8xml/XmlSerializer.h"
#include "v8xml/SerializerV2.h"
#include <boost/scoped_ptr.hpp>
#include <istream>

namespace RBX {
void ContentProvider::load(ContentId id, std::vector<boost::shared_ptr<Instance> >& instances)
{
    boost::scoped_ptr<std::istream> stream(getContent(id));
    TextXmlParser machine(stream->rdbuf());
    boost::scoped_ptr<XmlElement> root(machine.parse());
    SerializerV2().loadInstances(root.get(), instances);
}
}

template class boost::scoped_ptr<XmlElement>;
template class boost::scoped_ptr<std::basic_istream<char,std::char_traits<char> > >;
template class std::auto_ptr<std::basic_istream<char,std::char_traits<char> > >;

#include "util/ImageContent.h"

namespace RBX {
bool ContentProvider::registerFile(CachedContent* item)
{
    CachedContent temp;
    {
        boost::mutex::scoped_lock lock(contentCacheMutex);
        temp = *item;
    }
    if (!temp.filename) {
        std::istringstream stream(*temp.data);
        ContentId hash = registerImageContent(stream, Name::getNullName());
        std::string filename = findHashFile(hash);
        if (filename.empty()) return false;
        temp.filename.reset(new std::string(filename));
        boost::mutex::scoped_lock lock(contentCacheMutex);
        *item = temp;
    }
    return true;
}
}

#include "util/ContentProvider.h"

bool RBX::ContentProvider::isUrl(const std::string& value)
{
    if (value.find("http://") == 0) return true;
    if (value.find("https://") == 0) return true;
    return false;
}
