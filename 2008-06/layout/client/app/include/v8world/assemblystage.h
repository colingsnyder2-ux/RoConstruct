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
