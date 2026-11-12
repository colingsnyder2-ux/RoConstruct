// from server: 100% by EspClaude
// from server: 52% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_45abcbc6ab7dbbb1.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _DLL
#define _DLL
#endif
#include "v8world/World.h"
#include "v8world/ContactManager.h"
#include "v8world/Assembly.h"

namespace RBX
{
	// 2007-08 World::onAssemblyExtentsChanged walks one std::set<Primitive*> that the
	// target reads at assembly+0x30 (head at +0x34, node value at +0xc) and calls
	// contactManager (World+0x30)->onPrimitiveExtentsChanged for each element.
	struct AssemblyPrims2007
	{
		char pad_0[0x30];
		std::set<Primitive*> primitives;
	};

	void World::onAssemblyExtentsChanged(RBX::Assembly * a)
	{
		const AssemblyPrims2007* a7 = reinterpret_cast<const AssemblyPrims2007*>(a);
		for (std::set<Primitive*>::const_iterator it = a7->primitives.begin(); it != a7->primitives.end(); ++it)
		{
			contactManager->onPrimitiveExtentsChanged(*it);
		}
	}
}
