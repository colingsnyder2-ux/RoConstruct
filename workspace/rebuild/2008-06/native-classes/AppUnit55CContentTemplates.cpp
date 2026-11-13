// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native template instances of the util/ContentProvider.cpp unit in the application range 0055c000..00560000
// (inactive). Verified by tests/record_native_app_unit55c.py (receipt app-unit55c-working.json).
//
// All headers are read-only here. The unit includes the content-cache-inline variant of util/NativeContentProvider.h
// (ContentProvider owner), which declares RBX::operator<(const ContentId&, const ContentId&) inline: the original
// std::less<ContentId>::operator() 0055c000 and the map members that compare keys (_Lbound 0055ca90, find 0055e750,
// insert 0055eed0 / 0055ffc0, operator[] 00560720) call msvcp90 operator<(const string&, const string&) through the
// import directly, so the comparison is inline there; the out-of-line copy 0055bd50 is a one-jmp thunk to that import.
//
// Explicit instantiations only (no helper function that the binary does not contain):
//   * std::map<ContentId, ContentProvider::CachedContent> and its _Tree base (ContentProvider::contentCache, +0x178);
//   * the std::list<ContentRequest> (requestQueue, +0x138) and std::list<FailedUrl> (failedUrls, +0x154) members the
//     unit uses (ctor, push_back / push_front, erase, clear, dtor);
//   * std::vector<RequestCallback> (ContentRequest::callbacks);
//   * boost::shared_ptr<const std::string> from std::string* and its sp_counted_impl_p<std::string>;
//   * Name::declare<sContentProvider>() 0055ddb0 and NonFactoryProduct<Instance, sContentProvider>() 0055c080.
#include "content-cache-inline/util/NativeContentProvider.h"

namespace RBX
{
	template const Name& Name::declare<sContentProvider>();
	// 0055c080: Instance() 0055b7e0, then the ten NonFactoryProduct<Instance, sContentProvider> vtables
	// 0x82dba4 (+0x0) .. 0x82db28 (+0xc4), RTTI .?AV?$NonFactoryProduct@VInstance@RBX@@$1?sContentProvider@...
	template NonFactoryProduct<Instance, sContentProvider>::NonFactoryProduct();
}

template class std::map<RBX::ContentId, RBX::ContentProvider::CachedContent>;
template class std::_Tree<std::_Tmap_traits<RBX::ContentId, RBX::ContentProvider::CachedContent,
	std::less<RBX::ContentId>,
	std::allocator<std::pair<const RBX::ContentId, RBX::ContentProvider::CachedContent> >, false> >;

template std::list<RBX::ContentProvider::FailedUrl>::list();
template void std::list<RBX::ContentProvider::FailedUrl>::push_front(const RBX::ContentProvider::FailedUrl&);
template std::list<RBX::ContentProvider::FailedUrl>::iterator std::list<RBX::ContentProvider::FailedUrl>::erase(
	std::list<RBX::ContentProvider::FailedUrl>::const_iterator, std::list<RBX::ContentProvider::FailedUrl>::const_iterator);
template void std::list<RBX::ContentProvider::FailedUrl>::clear();
template std::list<RBX::ContentProvider::FailedUrl>::~list();

template std::list<RBX::ContentRequest>::list();
template void std::list<RBX::ContentRequest>::push_back(const RBX::ContentRequest&);
template std::list<RBX::ContentRequest>::iterator std::list<RBX::ContentRequest>::erase(
	std::list<RBX::ContentRequest>::const_iterator);
template void std::list<RBX::ContentRequest>::clear();
template std::list<RBX::ContentRequest>::~list();

template class std::vector<RBX::RequestCallback>;

template class boost::detail::sp_counted_impl_p<std::string>;
template boost::shared_ptr<const std::string>::shared_ptr(std::string*);
template void boost::shared_ptr<const std::string>::reset(std::string*);
