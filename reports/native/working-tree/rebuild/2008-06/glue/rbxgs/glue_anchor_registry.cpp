// Rebuild shim, tracked: the Anchor object of an anchored Primitive.
// rbxgs stores it in Primitive::anchorObject, but the 2008 Primitive (0xfc bytes, constructor 0x5e8770) has no
// such field, and 2008 anchors through an AnchorJoint class rbxgs does not have. This table keeps rbxgs's
// anchoring working on the 2008 layout until AnchorJoint is reconstructed; it is not recovered 2008 code.
#include "v8world/Primitive.h"
#include <map>

namespace RBX
{
	static std::map<const Primitive*, Anchor*>& anchors()
	{
		static std::map<const Primitive*, Anchor*> table;
		return table;
	}

	Anchor* Primitive::getAnchorObject() const
	{
		std::map<const Primitive*, Anchor*>::const_iterator it = anchors().find(this);
		return it == anchors().end() ? NULL : it->second;
	}

	void Primitive::setAnchorObject(Anchor* anchor)
	{
		if (anchor)
			anchors()[this] = anchor;
		else
			anchors().erase(this);
	}
}
