#pragma once
// >>> native-status (generated) -- do not edit >>>
// DebrisService | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src e0585a12 | roc native-status --write
// 2008-06 native RBX::DebrisService (inactive). Shape after the donor tools/rbxgs DebrisService.h; every base, field
// and virtual below is read from the 2008-06 binary:
//   RTTI       vtable 00849aec .?AVDebrisService@RBX@@ -> DescribedCreatable<DebrisService, Instance, sDebrisService>
//              (name mangled $1?sDebrisService@2@3PADA, a non-const char array in .data at 009611f0 holding "Debris":
//              doDeclare 005bfe20, classDescriptor 005c06a0) and the empty Service (mdisp 0x130).
//   size       0x158: Creatable<Instance>::create<DebrisService> 005c2e10 mallocs 0x158 and calls the constructor
//              0063be90.
//   ctor       0063be90 passes the class-name array itself to DescribedCreatable<..>::DescribedCreatable<const char*>
//              0063bdb0 (-> FactoryProduct<const char*> 0063b490 -> Instance(const char*) 0055b960), then builds the
//              std::deque of std::queue at +0x130 (VS2008 aux pointer new(4) at +0x130, map/mapsize/off/size at
//              +0x140..+0x14c), timer = 0 (+0x154) and maxItems = 300 (+0x150).
//   dtor       0063bfe0: deque _Tidy 0063b6d0, delete of the aux block, then ~FactoryProduct 0063b340 (deleting 0063c050).
//   vtable     slot 12 onServiceProvider 0063c280 (flushes the queue, does not call Instance::onServiceProvider,
//              timer = ServiceProvider::create<TimerService>(newProvider) through 00492020).
//   methods    getMaxItems 0063b330 (+0x150), setMaxItems 0063c3a0, addItem 0063bbc0 (TimerService::delay 005d6e10
//              when timer is set), cleanup 0063b9d0 (signed size compare against maxItems).
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include <boost/weak_ptr.hpp>
#include <queue>

struct NativeDebrisForceFieldLayout;

namespace RBX
{
	class TimerService;

	extern char sDebrisService[];

	class DebrisService : public DescribedCreatable<DebrisService, Instance, sDebrisService>,
						  public Service
	{
		friend struct ::NativeDebrisForceFieldLayout; // tests/NativeDebrisForceFieldLayout.cpp offset asserts

	private:
		std::queue<boost::weak_ptr<Instance> > queue;   // +0x130 (deque: aux +0x130, map +0x140, size +0x14c)
		int maxItems;                                   // +0x150
		TimerService* timer;                            // +0x154

	public:
		DebrisService();                                // 0063be90
		// ~DebrisService 0063bfe0 is implicit (deleting 0063c050).
		void addItem(boost::shared_ptr<Instance> item, double lifetime); // 0063bbc0
		void setMaxItems(int value);                    // 0063c3a0
		int getMaxItems() const                         // 0063b330 (out of line: the property getter)
		{
			return maxItems;
		}

	protected:
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 0063c280

	private:
		void cleanup();                                 // 0063b9d0
	};
}
