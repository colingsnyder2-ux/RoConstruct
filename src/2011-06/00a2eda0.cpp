// from server: 100% by auto
// roc 2011-06 00a2eda0  unit: seg_00a20000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a2eda0
//
// 00a2eda0  e82b45e2ff           call 0x8532d0
// 00a2eda5  a35c82d100           mov dword ptr [0xd1825c], eax
// 00a2edaa  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
