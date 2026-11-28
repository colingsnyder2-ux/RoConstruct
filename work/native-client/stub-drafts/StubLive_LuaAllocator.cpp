// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native LuaAllocator ctor 005c8920, member alloc 005c8dd0, static alloc 005c8e30 (the lua_Alloc openState
// passes to lua_newstate). Original bodies: ctor zeroes the four counters; member alloc = bucketRealloc<16,32> then
// heapSize += nsize - osize, heapCount +1 on a new block / -1 on a free, high-water marks; static alloc forwards to the
// member on ud. Both were `return 0` stubs: lua_newstate got a null allocator -> "Failed to create Lua state", no scripts.
// bucketRealloc: copied from Inferred_005c8fa0.cpp (body identical to the original 005c8c40, relocations masked).
#include "script/LuaMemory.h"
#include <boost/pool/singleton_pool.hpp>
#include <stdlib.h>
#include <string.h>

template <int a, int b>
void* bucketRealloc(void* ptr, size_t osize, size_t nsize)
{
	void* result;

	if (nsize > b)
	{
		if (osize <= b && osize)
		{
			result = malloc(nsize);
			memcpy(result, ptr, osize);

			if (osize > a)
				boost::singleton_pool<LuaAllocator, b>::free(ptr);
			else
				boost::singleton_pool<LuaAllocator, a>::free(ptr);
		}
		else
		{
			result = realloc(ptr, nsize);
		}
	}
	else
	{
		if (nsize > a)
		{
			if (osize > b)
			{
				result = boost::singleton_pool<LuaAllocator, b>::malloc();
				memcpy(result, ptr, nsize);
				free(ptr);
			}
			else
			{
				if (osize > a)
				{
					result = ptr;
				}
				else
				{
					result = boost::singleton_pool<LuaAllocator, b>::malloc();

					if (osize > 0)
					{
						memcpy(result, ptr, osize);
						boost::singleton_pool<LuaAllocator, a>::free(ptr);
					}
				}
			}
		}
		else
		{
			if (nsize > 0)
			{
				if (osize > b)
				{
					result = boost::singleton_pool<LuaAllocator, a>::malloc();
					memcpy(result, ptr, nsize);
					free(ptr);
				}
				else if (osize > a)
				{
					result = boost::singleton_pool<LuaAllocator, a>::malloc();
					memcpy(result, ptr, nsize);
					boost::singleton_pool<LuaAllocator, b>::free(ptr);
				}
				else if (osize > 0)
				{
					result = ptr;
				}
				else
				{
					result = boost::singleton_pool<LuaAllocator, a>::malloc();
				}
			}
			else
			{
				if (osize > b)
				{
					free(ptr);
				}
				else if (osize > a)
				{
					boost::singleton_pool<LuaAllocator, b>::free(ptr);
				}
				else if (osize > 0)
				{
					boost::singleton_pool<LuaAllocator, a>::free(ptr);
				}

				result = 0;
			}
		}
	}

	return result;
}


LuaAllocator::LuaAllocator() : heapSize(0), heapCount(0), maxHeapSize(0), maxHeapCount(0)
{
}

void* LuaAllocator::alloc(void* ptr, size_t osize, size_t nsize)
{
	void* result = bucketRealloc<16, 32>(ptr, osize, nsize);
	heapSize += nsize - osize;
	if (osize == 0)
		heapCount++;
	if (nsize == 0)
		heapCount--;
	maxHeapSize = (maxHeapSize < heapSize) ? heapSize : maxHeapSize;
	maxHeapCount = (maxHeapCount < heapCount) ? heapCount : maxHeapCount;
	return result;
}

void* LuaAllocator::alloc(void* ud, void* ptr, size_t osize, size_t nsize)
{
	return static_cast<LuaAllocator*>(ud)->alloc(ptr, osize, nsize);
}
