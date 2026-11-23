// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/engine-world
// 2008-06 native RBX::World::removeJoint 005ea3a0 (inactive; World.cpp unit 005e9150..005eaeef). Flags and the
// NATIVE_WORLD_LAYOUT include profile are copied from RBXWorldRecovery_005e9170.cpp (same unit, read-only here); the
// kernel-stages IStage (WorldJoint.cpp) gives IWorldStage::onEdgeRemoving its 2008 slot 5.
#undef _RELEASEASSERT
#define NATIVE_WORLD_LAYOUT
#include <set>
#include <G3D/Array.h>
#include "v8kernel/IPipelined2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Geometry2008.h"
#include "util/Extents.h"
#include "AppUnit658/Edge.h"
#include "v8world/Joints2008.h"
#include "v8world/Primitive2008.h"
#include "v8world/World2008.h"
#include "v8world/IWorldStage.h"

namespace RBX
{
	// INFERRED: file-local copy of the openrbx 2007 inline World::removeFromBreakable (World2008.h does not declare it).
	// 005ea3a0 stores the joint back into its argument slot before isBreakable, the by-value parameter of an inlined
	// helper whose address set::erase(const key&) takes.
	static inline void removeFromBreakable(std::set<Joint*>& breakableJoints, Joint* j)
	{
		if (j->isBreakable())
			breakableJoints.erase(j);
	}

	// 005ea3a0 (registry placeholder func_005ea3a0): callers JointInstance::onAncestorChanged 005e3a80,
	// VelocityMotor::onAncestorChanged 0060a0f0 and Joint::setJointCoord 00645750 (WorldJoint.cpp names it). Openrbx
	// 2007 World.cpp shape with the inline removeFromBreakable: Joint::isBreakable (slot 6) -> breakableJoints (+0xc4)
	// erase 005e9f60, jointStage (+0x88) onEdgeRemoving (slot 5), --numJoints (+0xe4).
	void World::removeJoint(Joint* j)
	{
		removeFromBreakable(breakableJoints, j);

		// INFERRED: World2008.h types jointStage as IStage* (2008: a CleanStage); the call is IWorldStage slot 5.
		static_cast<IWorldStage*>(jointStage)->onEdgeRemoving(j);

		numJoints--;
	}
}
