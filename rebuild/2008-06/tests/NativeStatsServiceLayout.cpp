// Layout probe for the inactive native Stats headers (native-headers/stats/); tests/record_native_stats_service.py
// checks each function body is `mov eax, imm32; ret` with the value from the binary:
//   sizeof(Stats::Item)               0x158  Creatable<Instance>::create<Item> 004b4e50 allocates 0x158
//   sizeof(Stats::TypedMemItem)       0x178  Creatable<Instance>::create<TypedMemItem> 005c9d40 allocates 0x178
//   sizeof(Stats::StatsService)       0x130  Creatable<Instance>::create<StatsService> 00458590 allocates 0x130
//   sizeof(WorkspaceStatsItem)        0x158  Creatable<Instance>::create<WorkspaceStatsItem> 005a6620 allocates 0x158
//   Item fields                       val +0x130 (fstp in 0045ebe0, fld in 005c8e50), sValue +0x138 (string ctor
//                                     in 0045ebe0, destructor 0045ba10)
//   TypedStatsItem<unsigned int>      func +0x158 (005bc860 stores the function vtable at +0x158, functor at +0x160;
//                                     TypedMemItem::update 005c9c50 calls operator() on +0x158)
// Field offsets are compile-time asserts (NativeStatsServiceLayout is a friend of Item and TypedStatsItem).
#include <stddef.h>
#include "stats/Stats.h"
#include "stats/WorkspaceStatsItem.h"

struct NativeStatsServiceLayout
{
	typedef char Val[offsetof(RBX::Stats::Item, val) == 0x130 ? 1 : -1];
	typedef char SValue[offsetof(RBX::Stats::Item, sValue) == 0x138 ? 1 : -1];
	typedef char Func[offsetof(RBX::Stats::TypedStatsItem<size_t>, func) == 0x158 ? 1 : -1];
};

size_t nativeStatsItemSize() { return sizeof(RBX::Stats::Item); }
size_t nativeStatsTypedMemItemSize() { return sizeof(RBX::Stats::TypedMemItem); }
size_t nativeStatsServiceSize() { return sizeof(RBX::Stats::StatsService); }
size_t nativeWorkspaceStatsItemSize() { return sizeof(RBX::WorkspaceStatsItem); }
