// Inactive native 2008-06 DHTMLWindowService and the Marshaller registry
// (native-headers/AppLeaves2008/DHTMLWindowService2008.h). The DHTMLWindow descriptors and methods of the same
// original unit (Navigate / SetBody / SetCallback / Resize / Show / Close / Bind / Unbind, DocumentComplete) are not
// recovered: they need the DHTMLWindow class of the unit around 00416e60.
#include "AppLeaves2008/DHTMLWindowService2008.h"

char sDHTMLWindowService[] = "HtmlService";   // 0092c1f8

namespace RBX
{
	// Template members the shared headers only declare (same definitions as Hopper.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}
}

static std::map<DWORD, Marshaller*> marshallers;   // 0096cec4 (initializer 007eef40, atexit 007fa640)
static boost::recursive_mutex marshallersLock;     // 0096cee4 (initializer 007eef70, atexit 007fa610)

Marshaller* acquireMarshaller()
{
	boost::recursive_mutex::scoped_lock lock(marshallersLock);
	DWORD threadId = ::GetCurrentThreadId();
	std::map<DWORD, Marshaller*>::iterator iter = marshallers.find(threadId);
	if (iter != marshallers.end())
	{
		iter->second->useCount++;
		return iter->second;
	}
	Marshaller* marshaller = new Marshaller(threadId);
	marshallers[threadId] = marshaller;
	marshaller->useCount++;
	return marshaller;
}

void initializeHtmlMarshaller()
{
	htmlMarshaller = acquireMarshaller();
}

DHTMLWindowService::DHTMLWindowService()
{
	setName("WindowService");
}
