// =============================================================================
// assemblystage.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8world/assemblystage.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <set>
#include "v8world/IWorldStage.h"

struct NativeAppUnit66CLayout;

namespace RBX
{
	class Assembly;
	class Edge;
	class Joint;
	class World;

	class AssemblyStage : public IWorldStage
	{
		friend struct ::NativeAppUnit66CLayout; // tests/record_native_app_unit66c.py offset probes

	private:
		std::set<Assembly*> assemblies;         // +0x10 (only the pointer-set shape is proven)
		std::set<Joint*> joints;                // +0x30

	public:
		AssemblyStage(IStage* upstream, World* world);      // 0066f800 (needs a 2008 SleepStage: not built)
		~AssemblyStage();                                   // 0066f790

		virtual StageType getStageType();                   // slot 1 (006fa3f0; not built, see the recorder)
#ifdef NATIVE_KERNEL_STAGE_NUMBERING
		virtual void stepWorld(int worldStepId, int uiStepId, bool throttling, bool moveBodiesTest);   // slot 2 (0066f570)
#else
		virtual void stepWorld(int worldStepId, int uiStepId, bool throttling);   // slot 2 (0066f570)
#endif
		virtual void onEdgeAdded(Edge* e);                  // slot 4 (0066f5f0; not built)
		virtual void onEdgeRemoving(Edge* e);               // slot 5 (0066f6e0; not built)

		void wakeAssembly(Assembly* assembly);              // 0066f510 (SleepStage 0064b890; not built)
		void onAssemblyAdded(Assembly* assembly);           // 0066f530 (SleepStage 0064aff0; not built)
		void onAssemblyRemoving(Assembly* assembly);        // 0066f550 (SleepStage 0064b0a0; not built)
	};
}
