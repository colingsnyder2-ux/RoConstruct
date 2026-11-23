// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/boost-function-pod-vtable /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/libs/boost_1_35_0
// 004b5100: explicit instantiation of the class the body at 004b5100 stores the vftable of (RTTI identity, twin_lane.py, no model)
// /I{headers}/boost-function-pod-vtable (Boost 1.35 function_template.hpp: static stored_vtable, inline assign_to down
// to has_empty_target 0060a2f0) makes the constructor TypedStatsItem<bool>(const bool*) 004b5100 194 B IDENTICAL with
// relocations masked (b46 hn03; without it 120 B, function0 constructor called out of line). It stays uncredited only
// because the registry row is the placeholder func_004b5100 with no candidate mapping (registry proposal:
// ??0?$TypedStatsItem@_N@Stats@RBX@@QAE@PB_N@Z). No exact lost (100 -> 100 rows).
#include "stats/Stats.h"
template class RBX::Stats::TypedStatsItem<bool>;
