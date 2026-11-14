// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Body::updatePV (inactive) against the Body layout of native-headers/v8kernel/Body2008.h.
// Flags copied from BodyPrimitive2008Body.cpp (the sibling Body rows).
// The other Body rows of this assignment already have bodies and are not repeated here:
//   accumulateTorque 006060b0 and getBranchMass 00613f00 are the out-of-line COMDATs of the in-class inline bodies in
//   native-headers/v8kernel/Body2008.h (Body::accumulateTorque / Body::getBranchMass).
#include "v8kernel/Body2008.h"
#include "PVFrameOps.h"

namespace RBX
{
	// 00599360 (?updatePV@Body@RBX@@ABEXXZ). Evidence from the target body: parent +0x14 tested first; the root
	// (+0x10) is brought up to date (recursive call) before its stateIndex +0x90 is compared with ours; the parent is
	// updated, the frame in parent is Link::getChildInParent 00613d60 when link +0x34 is set, else meInParent +0x38;
	// the parent pv +0x94 is re-read through getPV (second parent updatePV call) and transformed into pv +0x94 by the
	// cdecl helper 005991c0 (PVFrameOps.h, descriptive name); finally stateIndex = root stateIndex (root updated again).
	void Body::updatePV() const
	{
		if (parent)
		{
			const Body* rootNow = root;              // root read once per state-index read (edi in the target)
			rootNow->updatePV();
			if (stateIndex != rootNow->stateIndex)
			{
				parent->updatePV();
				const G3D::CoordinateFrame& meInParentNow = link ? link->getChildInParent() : meInParent;
				recoveredPVLocalFrame(parent->getPV(), meInParentNow, pv);
				const Body* rootAfter = root;
				rootAfter->updatePV();
				stateIndex = rootAfter->stateIndex;
			}
		}
	}
}
