// =============================================================================
// DebrisService.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/DebrisService.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
