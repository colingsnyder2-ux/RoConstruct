// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// INFERRED: sub_005c8ba0 (placeholder name for 005c8ba0 from the identity tier; body byte-proved against the native headers by the placeholder lane)
#include <script/LuaMemory.h>
#include <boost/pool/pool_alloc.hpp>
#include <boost/pool/singleton_pool.hpp>
#include "util/Name.h"

void __cdecl sub_005c8ba0(void* const ptr)
{
	boost::singleton_pool<LuaAllocator, 32, boost::default_user_allocator_new_delete, boost::details::pool::default_mutex, 32>::free(ptr);
}
