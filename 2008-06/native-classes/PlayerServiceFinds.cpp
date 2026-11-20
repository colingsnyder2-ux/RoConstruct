// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
// 2008-06 native ServiceProvider::find<C>() const rows of the RBX::Network::Player unit (0048c000..00498000) that call
// the boost::shared_ptr<Instance> destructor out of line (inactive). The rest of that unit (create<TimerService>
// 00492020, create<RunService> 004530f0, the vector<shared_ptr<Instance>> helpers) inlines the destructor, so these
// two rows are compiled here with the boost-noinline-shared-destructor variant, the same split as
// WorkspaceServiceFind.cpp / SoundServiceFind.cpp. Shape as in AppUnit48C_2008Services.cpp (v8tree/Service.h declares
// the templates without bodies).
//   find<StarterPackService>() const 00490d70 (320 B; caller find<StarterPackService>(const Instance*) 00491ef0 tail
//     jump; getClassIndex: call_once 00557330 on callDoGetClassIndex 0048ad80, doGetClassIndex 0048a520).
//   find<TimerService>() const 00490f10 (320 B; caller create<TimerService>() const 00492020; doGetClassIndex
//     0048a400).
// Batch 27 trial: the same bodies in AppUnit48C_2008Services.cpp with this variant are byte-exact, but nine rows of
// that unit (00412180 00412240 004124c0 004530f0 00456e80 00492020 004cb300 005a1990 005a27e0) are lost.
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/TimerService.h"

namespace RBX
{
	template<class Class, class Derived, const char* Name>
	const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }

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

	template StarterPackService* ServiceProvider::find<StarterPackService>() const; // 00490d70
	template TimerService* ServiceProvider::find<TimerService>() const;             // 00490f10
}
