// 2008-06 native rows of the Workspace.cpp unit (application range 005a4000..005a8000): the Stats::TypedStatsItem
// <double> / <float> update overrides the unit's stats items instantiate (inactive). Built against the committed
// native stats/Stats.h (read-only). Verified by tests/record_native_app_unit5a4.py.
//
// Evidence: slot 16 of the TypedStatsItem<double> vtable 00833b9c holds 005a4020 and slot 16 of the
// TypedStatsItem<float> vtable 00833c64 holds 005a4160 (RTTI .?AV?$TypedStatsItem@N@Stats@RBX@@ / @M@); both bodies
// call the boost::function0 at +0x158 (operator() 0042afc0) and pass the result to Item::formatValue<double>
// 005c90b0 / formatValue<float> 005c90e0.
#include "stats/Stats.h"

template void RBX::Stats::TypedStatsItem<double>::update(); // 005a4020
template void RBX::Stats::TypedStatsItem<float>::update();  // 005a4160
