// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers}/boost-function-pod-vtable /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/libs/boost_1_35_0
// 005bc860 ??0?$TypedStatsItem@I@Stats@RBX@@QAE@PBI@Z (registry name, 194 B): TypedStatsItem<unsigned int>(const unsigned*),
// the stats item SoundService creates through Creatable<Instance>::create<TypedStatsItem<unsigned>, const unsigned*>
// (AppUnit5B4SoundReflection.cpp). Same pattern and flags as TwinInst_004b5100.cpp (TypedStatsItem<bool>): the Boost
// 1.35 pod-vtable profile inlines assign_to down to has_empty_target. update() 005bc930 (34 B) is the instance's
// virtual update.
#include "stats/Stats.h"
template class RBX::Stats::TypedStatsItem<unsigned int>;
