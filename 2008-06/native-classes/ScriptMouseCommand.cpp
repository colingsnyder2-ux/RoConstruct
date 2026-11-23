// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::ScriptMouseCommand destructor (inactive), flags copied from Mouse.cpp (same subsystem).
// Statement shape from the 2007 openrbx Client/App/v8datamodel/ScriptMouseCommand.cpp.
#include "v8datamodel/ScriptMouseCommand.h"
#include "v8datamodel/Mouse.h"

namespace RBX
{
	// 00642fc0 (registry func_00642fc0): RTTI of the vtables it stores (0084a894 / 0084a87c) is
	// .?AVScriptMouseCommand@RBX@@; its deleting destructor is 006430c0 (vtable slot 0084a8c4). The inline
	// Mouse::setCommand(NULL) is the +0x164 store, SignalSource::disconnect_all_slots 0056bd60 runs on the Mouse's
	// SignalSource base (+0x14), then ~shared_ptr<Mouse> and ~MouseCommand 00615780.
	ScriptMouseCommand::~ScriptMouseCommand()
	{
		mouse->setCommand(NULL);

		mouse->disconnect_all_slots();
	}
}
