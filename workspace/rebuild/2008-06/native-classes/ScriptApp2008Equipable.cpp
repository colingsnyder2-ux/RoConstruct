// 2008-06 native RBX::IEquipable unit (inactive): the first Roblox application unit after the Lua 5.1.1 library
// (lbaselib luaopen_base 00628f50 ends at 00628f73). Rows: ~IEquipable 00628f80 (releases weld, the shared_ptr at
// +4/+8; ICF-shared with other shared_ptr-at-+4 destructors), IEquipable() 00628fc0 (zeroes +4/+8/+0xc: weld and
// workspace), buildWeld 00628fd0 (ret 0x14: five arguments; Creatable<Instance>::create<Weld> 004b2620 news 0x154 and
// calls Weld() 005e4810). Layout: vtable +0, shared_ptr<Weld> weld +4, Workspace* workspace +0xc (sizeof 0x10: the
// Accoutrement mdisp IEquipable 0x130 -> IRenderable 0x140, Tool 0x1a0 -> 0x1b0), declared by the donor
// v8datamodel/IEquipable.h that the native Tool.h / Accoutrement.h already include.
// Verified by tests/record_native_script_app2008.py.
#include "v8datamodel/IEquipable.h"
#include "v8datamodel/JointInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	IEquipable::IEquipable()
		: workspace(NULL)
	{
	}

	IEquipable::~IEquipable()
	{
	}

	void IEquipable::buildWeld(PartInstance* humanoidPart, PartInstance* gadgetPart, const G3D::CoordinateFrame& humanoidCoord,
							   const G3D::CoordinateFrame& gadgetCoord, const std::string& name)
	{
		G3D::CoordinateFrame attachmentCoordWorld = humanoidPart->getCoordinateFrame() * humanoidCoord;
		G3D::CoordinateFrame gadgetCoordWorld = attachmentCoordWorld * gadgetCoord.inverse();

		gadgetPart->setCoordinateFrame(gadgetCoordWorld);

		weld = Creatable<Instance>::create<Weld>();

		weld->setName(name);
		weld->setPart0(humanoidPart);
		weld->setPart1(gadgetPart);
		weld->setC0(humanoidCoord);
		weld->setC1(gadgetCoord);
		weld->setParent(humanoidPart);
	}
}
