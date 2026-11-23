// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native Lua::ThreadRef::syncSingleton (inactive): boost::shared_ptr<boost::mutex> at 00975c6c (.bss, null; the
// first ThreadRef ctor copies it into +4/+8 -- see LuaThreadRef.cpp).
#include "script/ThreadRef.h"
#include "script/ScriptContext.h"

namespace RBX
{
	namespace Lua
	{
		boost::shared_ptr<boost::mutex> ThreadRef::syncSingleton;
	}
}
