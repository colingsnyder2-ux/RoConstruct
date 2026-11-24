// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8world/JointStage.h"

// INFERRED: 0x006a0920 is the allocator the original calls (push 0x30; call; add esp,4), so it is
// declared as a one-argument cdecl allocator instead of the six-argument form in the callee list.
extern "C" void* fn_006a0920(unsigned int size);

namespace RBX
{
	// INFERRED: unit-local copy of the ClumpStage declaration (as in the sibling JointStage2008.cpp),
	// because only the constructor 0x0064cfd0 is called here. Same members and order as ClumpStage2008.h.
	class ClumpStage : public IWorldStage
	{
	private:
		std::set<Edge*> set10;

	public:
		ClumpStage(IStage* upstream, World* world); // 0064cfd0
		~ClumpStage();

		virtual StageType getStageType();
		virtual void onEdgeAdded(Edge* e);
		virtual void onEdgeRemoving(Edge* e);

		// INFERRED: routes allocation through the original's allocator at 0x006a0920.
		static void* operator new(size_t size)
		{
			return fn_006a0920((unsigned int)size);
		}
		static void operator delete(void* p)
		{
			::operator delete(p);
		}
	};

	// 00668470: new(0x30) ClumpStage(this, world) is the downstream, built before the IStage fields.
	// The std::set (+0x10) and std::multimap (+0x30) members are then default-constructed.
	JointStage::JointStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new ClumpStage(this, world), world)
	{
	}
}
