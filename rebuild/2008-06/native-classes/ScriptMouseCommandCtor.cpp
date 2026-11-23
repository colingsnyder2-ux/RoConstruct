// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::ScriptMouseCommand constructor (inactive). Its unit is ScriptMouseCommand.cpp (destructor
// 00642fc0, flags copied from it); that file is not this batch's, so this row has its own unit (the MotorDefaultCtor.cpp
// pattern). Statement shape from the 2007 openrbx Client/App/v8datamodel/ScriptMouseCommand.cpp.
#include "v8datamodel/ScriptMouseCommand.h"
#include "v8datamodel/Mouse.h"
#include "util/Object.h"

namespace RBX
{
	// 006430e0 (placeholder func_006430e0; callers HopperBin::onSelectScript 005d1240 and 005fe280): MouseCommand(Workspace*)
	// 006159f0, the ScriptMouseCommand vtables 0084a894 / 0084a87c (RTTI .?AVScriptMouseCommand@RBX@@), mouse (+0x1c)
	// assigned from Creatable<Instance>::create<Mouse> 005ff600 (px store, shared_count::operator= 004025b0, temporary
	// released), then the inline Mouse::setCommand (Mouse +0x164 = this).
	ScriptMouseCommand::ScriptMouseCommand(Workspace* workspace)
		: MouseCommand(workspace)
	{
		mouse = Creatable<Instance>::create<Mouse>();
		mouse->setCommand(this);
	}
}
