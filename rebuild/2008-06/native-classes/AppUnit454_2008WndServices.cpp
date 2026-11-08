// 2008-06 native ServiceProvider / Creatable / FactoryProduct template instances in the CRobloxWnd unit (application
// range 00454000..00460000, inactive). Verified by tests/record_native_app_unit454_2008.py. All headers are read-only.
//
// The rows lie in the COMDAT run of the CRobloxWnd unit (vtable 008199f4; its setDataModel 0045f7b0 calls
// create<ControllerService>):
//   * Name::doDeclare<sCamera>() 0045b240 (101 B, "Camera") and callDoDeclare<sCamera>() 0045b6f0 (5 B, a tail jump);
//     the static initializers 007ef9f0 / 007faf40 call doDeclare;
//   * ServiceProvider::doGetClassIndex<ControllerService>() 0045b2b0 (91 B, newIndex 00572690) and
//     callDoGetClassIndex<ControllerService>() 0045b820 (5 B);
//   * ServiceProvider::find<ControllerService>() const 0045dce0 (320 B) and create<ControllerService>() const 0045de20
//     (228 B), the same bodies as the Stats::StatsService rows of AppUnit454_2008ReportStats.cpp;
//   * Creatable<Instance>::create<C>() (120 B) and shared_ptr<C>(C*, Creatable<Instance>::Deleter) (171 B) for
//     ControllerService 0045c580 / 0045c1a0 (malloc 0x144, ControllerService() 005cb9e0) and Camera 0045db40 /
//     0045da90 (Camera() 005cd9a0);
//   * FactoryProduct<C, Instance, sC>::Creator::create() const (175 B, slot 0 of the one-slot Creator vtable) for
//     ControllerService 0045d950 (vtable 00819d8c) and Camera 0045dbc0 (vtable 00819d94);
//   * Instance::for_eachChild<void (*)(Instance*)>(void (*)(Instance*)) const 0045c470 (260 B; inline member template
//     of v8tree/Instance.h, first emitted here: callers 0045c600 / 0045e3f0 in this unit, 0048c3e0 / 004add50 later).
// v8tree/Service.h and util/Object.h declare these templates without bodies; the definitions below are the ones
// AppUnit48C_2008Services.cpp and AppUnit400_2008Creators.cpp use.
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/UserController.h"
#include "v8datamodel/Camera.h"
#include "util/Object.h"

namespace RBX
{
	template<class Class, class Derived, const char* Name>
	const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }

	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}

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

	template ControllerService* ServiceProvider::find<ControllerService>() const;
	template ControllerService* ServiceProvider::create<ControllerService>() const;

	template const Name& Name::declare<sCamera>();
	template boost::shared_ptr<Object> FactoryProduct<ControllerService, Instance, sControllerService>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<Camera, Instance, sCamera>::Creator::create() const;

	template void Instance::for_eachChild<void (*)(Instance*)>(void (*)(Instance*)) const;
}
