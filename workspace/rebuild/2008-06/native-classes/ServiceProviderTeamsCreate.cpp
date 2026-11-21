// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native ServiceProvider service-template rows of the COMDAT run 004b3060..004b3d70 (inactive):
//   * create<Teams>() const 004b3b40 (228 B): ??$create@VTeams@RBX@@@ServiceProvider@RBX@@QBEPAVTeams@1@XZ (registry).
//     find<Teams>() const 0049a580, else Creatable<Instance>::create<Teams>() 00490450, getClassIndex (call_once
//     00557330 on callDoGetClassIndex<Teams> 004969f0, doGetClassIndex 004962f0), the checked serviceArray store
//     (shared_ptr assign 004025b0), setParent(this) 0055a8f0, shared_ptr<Teams> release inline. Same generic create<C>()
//     shape as create<TimerService> 00492020 (AppUnit48C_2008Services.cpp) and create<ContentProvider> 0041eea0.
//   * callDoGetClassIndex<JointsService>() 004ac610 (5 B tail jump to doGetClassIndex 004ab4d0; passed to call_once by
//     find<JointsService> 004b34c0).
// v8tree/Service.h declares these templates without bodies; the definitions are the ones AppUnit48C_2008Services.cpp
// uses. find<JointsService> 004b34c0 itself is defined (near miss) in JointsService.cpp: not duplicated here.
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/JointsService.h"

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

	// 004b3b40 (228 B).
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

	template Teams* ServiceProvider::create<Teams>() const;                  // 004b3b40
	template void ServiceProvider::callDoGetClassIndex<JointsService>();     // 004ac610
}
