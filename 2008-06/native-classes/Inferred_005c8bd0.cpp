// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005c8bd0 (placeholder name for 005c8bd0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <script/LuaMemory.h>
#include <boost/pool/pool_alloc.hpp>
#include <boost/pool/singleton_pool.hpp>
#include "util/Name.h"

void* __cdecl sub_005c8bd0()
{
	return boost::singleton_pool<LuaAllocator, 16, boost::default_user_allocator_new_delete, boost::details::pool::win32_mutex, 32>::malloc();
}
