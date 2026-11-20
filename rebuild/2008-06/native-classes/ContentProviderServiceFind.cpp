// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
// 2008-06 native ServiceProvider::find<ContentProvider>() const 0041ed60 (320 B, inactive). Identity: registry decorated
// name ??$find@VContentProvider@RBX@@@ServiceProvider@RBX@@QBEPAVContentProvider@1@XZ (reference vote); the body is the
// generic find<C>() shape of v8tree/Service.h (getClassIndex call_once, serviceArray +0x190 resize / lookup, else
// findServiceByClassName(className()) 00572a90 and the store) with the shared_ptr<Instance> destructor called out of
// line, as in WorkspaceServiceFind.cpp / SoundServiceFind.cpp (same variant flag).
#include "util/NativeContentProvider.h"
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"

namespace RBX
{
	template<class Class, class Derived, const char* Name>
	const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }

	// ContentProvider is a DescribedNonCreatable: its className() (util/Object.h declares it) is the inline
	// Name::declare<sContentProvider>() the target expands (call_once 00557330 on callDoDeclare 0041e0f0, doDeclare
	// 0041dfe0); same definition as AppUnit568GlobalSettings.cpp / Feature.cpp.
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

	template ContentProvider* ServiceProvider::find<ContentProvider>() const; // 0041ed60
}
