// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native Lua::ThreadRef::syncSingleton: boost::shared_ptr<boost::mutex> at 00975c6c,
// initialized with new boost::mutex() by CRT initializer 007f4110 (orig 007f4127..007f4156).
#include "script/ThreadRef.h"
#include "script/ScriptContext.h"

namespace RBX
{
	namespace Lua
	{
		boost::shared_ptr<boost::mutex> ThreadRef::syncSingleton(new boost::mutex());
	}
}
