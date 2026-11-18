#pragma once
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
