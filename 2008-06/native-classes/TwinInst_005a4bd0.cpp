// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /I{headers} /I{headers}/../../../tools/rbxgs/Client/App/include /I{headers}/../../../tools/libs/boost_1_35_0
// 005a4bd0: explicit instantiation of the class the body at 005a4bd0 stores the vftable of (RTTI identity, twin_lane.py, no model)
#include "stats/Stats.h"
template class RBX::Stats::TypedStatsItem<float>;
template boost::shared_ptr<RBX::Stats::TypedStatsItem<float>> RBX::Creatable<RBX::Instance>::create<RBX::Stats::TypedStatsItem<float>, boost::function0<float, std::allocator<boost::function_base> >>(boost::function0<float, std::allocator<boost::function_base> >);
