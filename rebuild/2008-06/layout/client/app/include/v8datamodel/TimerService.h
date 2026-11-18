#pragma once
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
		void delay(boost::function0<void> func, double seconds); // 005d6e10

	protected:
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 005d73a0
		virtual void onEvent(const RunService* source, Heartbeat event); // 005d6f70
	};
}
