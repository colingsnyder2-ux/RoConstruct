// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005c8b60 (placeholder name for 005c8b60 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <boost/pool/pool.hpp>
#include <boost/pool/singleton_pool.hpp>
#include <script/LuaMemory.h>
#include "util/Name.h"

void* sub_005c8b60()
{
	return boost::singleton_pool<LuaAllocator, 32, boost::default_user_allocator_new_delete, boost::details::pool::win32_mutex, 32>::malloc();
}
