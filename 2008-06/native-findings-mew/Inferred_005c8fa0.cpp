// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source /FIwinsock2.h /I{headers}/../../../tools/rbxgs/Client/Network
// 005c8fa0: real name from the identity registry; body byte-proved against the native headers (named lane)
#include "Replicator.h"
#include "util/Log.h"
#include "util/Name.h"

namespace RBX {

template<>
void Stats::Item::formatValue<G3D::Stopwatch>(const G3D::Stopwatch& sw)
{
	val = sw.smoothElapsedTime();
	if (sw.smoothElapsedTime() > 0) {
		std::string t = Log::formatTime(sw.smoothElapsedTime());
		sValue = G3D::format("%s (%.3gfps)", t.c_str(), 1.0 / sw.smoothElapsedTime());
	} else {
		sValue = Log::formatTime(sw.smoothElapsedTime());
	}
}

}

// LuaAllocator realloc lane (application range 005c8930..005c8e30, the LuaAllocator unit: clearHeapMax 005c8930,
// getHeapStats 005c8960, the singleton_pool<LuaAllocator, 16/32> malloc/free helpers 005c8b60 / 005c8ba0 / 005c8bd0 /
// 005c8c10 that the realloc calls). Bodies follow the rbxgs / openrbx LuaMemory.cpp analog; lua_newstate receives
// LuaAllocator::alloc (static) from ScriptContext, which forwards to the member below.
#include "script/LuaMemory.h"
#include <boost/pool/singleton_pool.hpp>
#include <algorithm>

// 005c8930 (9 B): rbxgs / openrbx LuaMemory.cpp LuaAllocator::clearHeapMax.
void LuaAllocator::clearHeapMax()
{
	maxHeapSize = 0;
	maxHeapCount = 0;
}

// 005c8960 (38 B, ret 0x10; caller ScriptContext stats 005aefa0 unit): rbxgs / openrbx LuaMemory.cpp
// LuaAllocator::getHeapStats, the four fields +0x0 / +0x4 / +0x8 / +0xc in order.
void LuaAllocator::getHeapStats(size_t& heapSize, size_t& heapCount, size_t& maxHeapSize, size_t& maxHeapCount) const
{
	heapSize = this->heapSize;
	heapCount = this->heapCount;
	maxHeapSize = this->maxHeapSize;
	maxHeapCount = this->maxHeapCount;
}

// Original 005c8c40 (394 B): ??$bucketRealloc@$0BA@$0CA@@@YAPAXPAXII@Z.
// Body IDENTICAL to the original (relocations masked, batch 48); unproved only because its callees 005c8b60 /
// 005c8ba0 / 005c8bd0 / 005c8c10 (singleton_pool<LuaAllocator, 32 / 16>::malloc / free) still carry placeholder
// identities (registry rename proposal), so the binder cannot establish the call references.
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

// Original 005c8dd0 (90 B, ret 0xc): ?alloc@LuaAllocator@@QAEPAXPAXII@Z.
void* LuaAllocator::alloc(void* ptr, size_t osize, size_t nsize)
{
	void* result = bucketRealloc<16, 32>(ptr, osize, nsize);

	heapSize += (nsize - osize);

	if (osize == 0)
		heapCount++;

	if (nsize == 0)
		heapCount--;

	maxHeapSize = std::max<size_t>(maxHeapSize, heapSize);
	maxHeapCount = std::max<size_t>(maxHeapCount, heapCount);

	return result;
}
