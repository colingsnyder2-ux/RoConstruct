// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::HopperBin selection bodies (inactive), split from the original Hopper unit 005cf160..005d1770
// (native-classes/Hopper.cpp holds the rest; classes and layout in native-headers/v8datamodel/Hopper.h, read-only).
// Bodies after the donor tools/rbxgs v8datamodel/Hopper.cpp; identities from work/2008-06/identity-registry.json and
// the only caller HopperBin::onLocalClicked 005d1340.
//   onSelectScript  005d1240: ServiceProvider::find<Workspace> 00491e50, new ScriptMouseCommand (0x24 bytes, ctor
//                   006430e0), Workspace::setMouseCommand 005a1fc0, ScriptMouseCommand::getMouse 005cf8d0 (out of
//                   line in this unit), desc_Selected (00979d18) SignalDescImpl<1,...>::fire 0049d200 with this+0x14
//                   (the SignalSource base).
//   onSelectCommand 005d0ec0: inline first step of Instance::getRootAncestor (parent +0x104) then the out-of-line
//                   0042a5f0; EnumDesc<BinType>::singleton (call_once 00557330 / 005d0300), convertToString 00448360,
//                   + "Tool" (0083 90e0), DataModel VerbContainer (+0x1c8) getVerb(std::string) 00583380, Verb slot 2
//                   isEnabled, Verb slot 4 doIt(&workspace->getDataState()) (Workspace +0x3a8).
//   drawSelected    005d1670 (`return active;`) is already the inline body in Hopper.h; not duplicated here.
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ScriptMouseCommand.h"
#include "v8datamodel/Mouse.h"

namespace RBX
{
	// Defined in native-classes/Hopper.cpp (00979d18). Proposal: drop `static` there so this unit can link to it.
	extern Reflection::SignalDesc<HopperBin, void(boost::shared_ptr<Instance>)> desc_Selected;

	// 005d1240
	void HopperBin::onSelectScript()
	{
		Workspace* workspace = ServiceProvider::find<Workspace>(this);
		if (workspace)
		{
			ScriptMouseCommand* command = new ScriptMouseCommand(workspace);
			workspace->setMouseCommand(command);
			desc_Selected.fire(this, command->getMouse());
		}
	}
}
