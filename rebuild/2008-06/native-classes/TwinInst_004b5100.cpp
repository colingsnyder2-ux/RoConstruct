// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/libs/boost_1_35_0
// 004b5100: explicit instantiation of the class the body at 004b5100 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "stats/Stats.h"
template class RBX::Stats::TypedStatsItem<bool>;
