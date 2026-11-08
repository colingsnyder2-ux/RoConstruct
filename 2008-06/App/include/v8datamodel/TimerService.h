#pragma once
// >>> native-status (generated) -- do not edit >>>
// TimerService | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 7640981d | roc native-status --write
// 2008-06 native RBX::TimerService (inactive). Shape after the donor tools/rbxgs TimerService.h; every base, field
// and virtual below is read from the 2008-06 binary:
//   RTTI       vtable 0083d1a4 .?AVTimerService@RBX@@ -> DescribedCreatable<TimerService, Instance, sTimerService>
//              (name mangled $1?sTimerService@2@3PADA, a non-const char array in .data at 00953654 holding
//              "Timer", the 2008 class name: doDeclare 0048a250), Listener<RunService, Heartbeat>
//              (mdisp 0x130, vtable 0083d118: onEvent 005d6f70, deleting thunk 005d7270) and the empty Service
//              (mdisp 0x134; MSVC places the vfptr-carrying Listener first).
//   size       0x158: constructor 005d71b0 stores the Listener vtable at +0x130, zeroes runService (+0x134/+0x138)
//              and builds std::list<Item> at +0x13c (list ctor 0055e590; head +0x150, size +0x154 read by onEvent
//              through the Listener subobject as +0x20/+0x24).
//   Item       list node allocated with new(0x30) by _Buynode/insert 005d6bf0: next, prev, Item at +8
//              (double time +8, boost::function0<void> func +0x10; _Construct 005d6b60).
//   vtable     slot 12 onServiceProvider 005d73a0 (does not call Instance::onServiceProvider in 2008).
//   delay      005d6e10 walks the list forward and inserts before the first later item, else push_back
//              (inlined: _Buynode 005d6bf0 + _Incsize 005d6ac0).
//   No setName in the constructor; no descriptors (only the class descriptor 005c0710).
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "util/RunStateOwner.h"
#include <boost/function.hpp>
#include <list>

struct NativeSpawnLayout;

namespace RBX
{
	extern char sTimerService[];

	class TimerService : public DescribedCreatable<TimerService, Instance, sTimerService>,
						 public Service,
						 public Listener<RunService, Heartbeat>
	{
		friend struct ::NativeSpawnLayout; // tests/NativeSpawnLayout.cpp offset asserts

		class Item
		{
		public:
			double time;                           // node +0x08 (G3D::RealTime)
			boost::function0<void> func;           // node +0x10
		};

	private:
		boost::shared_ptr<RunService> runService;  // +0x134
		std::list<Item> items;                     // +0x13c

	public:
		TimerService();                            // 005d71b0
		// ~TimerService 005d72f0 is implicit (deleting 005d7380).
		void delay(boost::function0<void> func, double seconds); // 005d6e10

	protected:
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 005d73a0
		virtual void onEvent(const RunService* source, Heartbeat event); // 005d6f70
	};
}
