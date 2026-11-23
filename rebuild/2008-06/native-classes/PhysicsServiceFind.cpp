// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/boost-noinline-shared-destructor /I{headers}/part-embedded /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native ServiceProvider::find<PhysicsService>() const 004ccca0 (inactive), the instance the PhysicsSender
// range (004ca000..004ce000) emits: getClassIndex<PhysicsService>() (call_once 00557330 on callDoGetClassIndex
// 004ca350 / flag 00971ad4), the serviceArray resize 004124c0 / lookup, else findServiceByClassName 00572a90 with the
// inlined PhysicsService::className() (call_once on callDoDeclare<sPhysicsService> 004ca340 / flag 00971ad0, then
// doDeclare 004c9b70) and the serviceArray store. Callers: ServiceProvider::find<PhysicsService>(const Instance*)
// 0066f020 (HumanoidStates3.cpp) tail-jumps to it.
// Kept in its own unit like AppUnit450ServiceFind.cpp: the original calls ~shared_ptr<Instance> 00600660 out of line,
// which needs native-headers/boost-noinline-shared-destructor first on the include path; that overlay costs 22 exact
// rows of PhysicsSenderRecovery_004cce00.cpp (measured, batch 47 nr01), so the body cannot live there.
// Template definitions: the unit-local ones of AppUnit450ServiceFind.cpp / AppUnit454_2008ReportStats.cpp
// (v8tree/Service.h and util/Object.h declare them without bodies).
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/PhysicsService.h"
#include "util/Object.h"

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

	// 004ccca0
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

	template PhysicsService* ServiceProvider::find<PhysicsService>() const; // 004ccca0
}
