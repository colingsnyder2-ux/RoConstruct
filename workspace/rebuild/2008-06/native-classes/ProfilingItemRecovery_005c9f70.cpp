// native-flags: /O2 /Ob2 /Oy /GS /GS- /EHsc /MD /D_NativeClass
// ProfilingItem (global namespace, RTTI 00839f0c) is recovered in native-classes/StatsService.cpp, the unit that owns
// the original range 005c8e50..005ca365: constructor 005c9f70, update 005c9fe0, getTimes 005c9440 (not exact yet),
// Creatable<Instance>::create<ProfilingItem> 005ca1c0, Item::createBoundChildItem 005ca240 and the GetTimes
// descriptor initializer 007f5cb0. This file held an earlier, non-compiling duplicate of that class (undeclared
// Bucket / Reflection names, placement-new into Tuple) together with duplicate template instantiations; it no longer
// defines anything, so the bodies have a single provider.
