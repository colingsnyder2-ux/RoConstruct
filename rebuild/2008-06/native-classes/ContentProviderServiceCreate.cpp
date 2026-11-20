// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native ServiceProvider::create<ContentProvider>() const 0041eea0 (228 B, inactive). Identity: registry decorated
// name ??$create@VContentProvider@RBX@@@ServiceProvider@RBX@@QBEPAVContentProvider@1@XZ; callers CRobloxWnd::finishAttach
// 0045ead0 and the ContentItem browse overrides 00441bc0 / 00441d60 (AppLeftovers.cpp). Body: find<ContentProvider>()
// 0041ed60 (ContentProviderServiceFind.cpp), else Creatable<Instance>::create<ContentProvider>() 0041e5d0,
// getClassIndex (call_once 00557330 on callDoGetClassIndex 0041e220, doGetClassIndex 0041e050), the checked serviceArray
// (+0x19c..+0x1a0) store (shared_ptr assign 004025b0), setParent(this) 0055a8f0, and the shared_ptr<ContentProvider>
// release inline. It is the generic create<C>() shape of AppUnit48C_2008Services.cpp (create<TimerService> 00492020).
// Kept apart from ContentProviderServiceFind.cpp: that unit needs the out-of-line shared_ptr destructor variant for
// find<ContentProvider>, while this body releases its shared_ptr inline.
#include "util/NativeContentProvider.h"
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"

namespace RBX
{
	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

	template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
	template<class Class> size_t ServiceProvider::getClassIndex()
	{
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}

	template<class Class> Class* ServiceProvider::find() const
	{
		size_t index = getClassIndex<Class>();
		Class* service;
		if (index + 1 > serviceArray.size())
		{
			serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
			service = NULL;
		}
		else
		{
			service = static_cast<Class*>(serviceArray[index].get());
			if (service != NULL)
				return service;
		}
		boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
		if (!item)
			return NULL;
		service = static_cast<Class*>(item.get());
		serviceArray[index] = item;
		return service;
	}

	// 0041eea0 (228 B).
	template<class Class> Class* ServiceProvider::create() const
	{
		Class* service = find<Class>();
		if (service == NULL)
		{
			boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
			service = value.get();
			size_t index = getClassIndex<Class>();
			serviceArray[index] = value;
			service->setParent(const_cast<ServiceProvider*>(this));
		}
		return service;
	}

	template ContentProvider* ServiceProvider::create<ContentProvider>() const; // 0041eea0
}
