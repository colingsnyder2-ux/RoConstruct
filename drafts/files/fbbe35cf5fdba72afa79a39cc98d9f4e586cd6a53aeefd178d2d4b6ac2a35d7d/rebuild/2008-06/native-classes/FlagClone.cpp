// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Flag (inactive): the clone/timer/stand half of the original Flag unit (00618380..00619a60).
// Flag.cpp (read-only, another contributor) holds the descriptor, constructor, destructor and accessors; this unit
// adds doUglyPeriodicCloneHack 00618f70, onServiceProvider 006194a0 and onChildAdded 00619970. Shapes follow the
// donor Flag.cpp; every call target below is read from the 2008-06 bodies (identity registry names in comments).
#include "v8datamodel/Flag.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/FlagStandService.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/TimerService.h"
#include "util/RunStateOwner.h"
#include <boost/bind.hpp>

namespace RBX
{
	// 00618f70: evilClone = clone() (Instance::clone 00559350, shared_count::operator= 004025b0); re-arms the
	// timer (TimerService::delay 005d6e10, 2.0 at 00826fd0) only while the flag has no children (+0x108 children).
	void Flag::doUglyPeriodicCloneHack()
	{
		evilClone = clone();

		if (timer && numChildren() == 0)
		{
			timer->delay(boost::bind(&Flag::doUglyPeriodicCloneHack, shared_from(this)), 2.0);
		}
	}

	// 006194a0: create<TimerService> 00492020, delay 005d6e10, connection::disconnect 00595230,
	// create<RunService> 004530f0 (runState +0x1b4 == RS_RUNNING), create<FlagStandService>(this) 00619450,
	// FindStandWithFlag 0062bfc0, FindClosestEmptyStandForFlag 0062c2e0, FlagStand::AffixFlag 0062bdc0.
	void Flag::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (!oldProvider)
		{
			timer = ServiceProvider::create<TimerService>(newProvider);
			timer->delay(boost::bind(&Flag::doUglyPeriodicCloneHack, shared_from(this)), 2.0);
		}

		if (!newProvider)
		{
			flagTouched.disconnect();
			RunService* runService = ServiceProvider::create<RunService>(oldProvider);

			if (runService->getRunState() == RS_RUNNING)
			{
				if (Instance* evilC = evilClone.get())
				{
					Flag* flag = dynamic_cast<Flag*>(evilC);
					flag->getHandle();

					FlagStandService* flagStandService = ServiceProvider::create<FlagStandService>(this);
					if (!flagStandService->FindStandWithFlag(flag))
					{
						if (FlagStand* flagStand = flagStandService->FindClosestEmptyStandForFlag(flag))
						{
							flagStand->AffixFlag(flag);
						}
					}
				}
			}
		}
	}

	// 00619970: dynamic_cast<PartInstance*>, Tool::getHandle 005fd760, event_Touched (00976164)
	// TSignalDesc::connect 004a3340 with priority 10, scoped_connection::operator= 00595540.
	void Flag::onChildAdded(Instance* instance)
	{
		if (dynamic_cast<PartInstance*>(instance))
		{
			if (PartInstance* handle = getHandle())
			{
				flagTouched = PartInstance::event_Touched.connect(handle, boost::bind(&Flag::onEvent_flagTouched, this, _1), 10);
			}
		}
	}
}

// ServiceProvider member templates for FlagStandService, emitted in the Flag unit of the original (00618380..00619a60):
// doGetClassIndex<FlagStandService> 00618520 (call_once 00557330 on callDoGetClassIndex 00618650, once flag 0097bf18),
// find<FlagStandService>() const 00619080 (registry placeholder func_00619080, 320 B: serviceArray +0x190 resize /
// lookup, findServiceByClassName(className()) 00572a90) and create<FlagStandService>() const 00619360 (calls 00619080,
// Creatable<Instance>::create<FlagStandService> 005c12b0, setParent 0055a8f0). v8tree/Service.h declares them without
// bodies; these are the definitions AppUnit454_2008ReportStats.cpp / AppUnit48C_2008Services.cpp use. The static
// create<FlagStandService>(const Instance*) 00619450 is instantiated by ServiceProviderStaticFind2008.cpp.
#include <boost/thread/once.hpp>

namespace RBX
{
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

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

	template FlagStandService* ServiceProvider::find<FlagStandService>() const;   // 00619080
	template FlagStandService* ServiceProvider::create<FlagStandService>() const; // 00619360
}
