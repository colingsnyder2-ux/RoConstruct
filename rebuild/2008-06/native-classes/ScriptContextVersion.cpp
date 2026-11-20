// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::getVersion 005a8720 (inactive), the lua_CFunction ScriptContext::openState 005aefa0 registers
// as the global 'version' (declared in native-headers/script/ScriptContext.h). Flags follow
// ScriptContextRecovery_005aefa0.cpp (the openState unit).
// Evidence (005a8720, 39 B): c_str() of the std::string at 00970b88 (Network::API::version: the same object the
// Server SetIncomingPassword / Client Connect paths read; _Myres +0x18 tested against 0x10), lua_pushstring
// (00612280, placeholder name), return 1.
#include "script/ScriptContext.h"
#include "Network/API.h"

namespace RBX
{
	// 005a8720
	int getVersion(lua_State* L)
	{
		lua_pushstring(L, Network::API::version.c_str());
		return 1;
	}
}
