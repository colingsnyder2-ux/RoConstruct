// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../native-classes
// 00456400: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "AppUnit454_2008ReportStats.cpp"
// INFERRED: 00456400 is a 5-byte jump to RBX::ServiceProvider::doGetClassIndex<class RBX::Stats::StatsService>; the forwarder name and owner are placeholders.
unsigned int __cdecl sub_00456400() { return RBX::ServiceProvider::doGetClassIndex<class RBX::Stats::StatsService>(); }
