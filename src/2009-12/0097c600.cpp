// from server: 100% by auto
// roc 2009-12 0097c600  unit: seg_00970000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c600
//
// 0097c600  e83b4be9ff           call 0x811140
// 0097c605  a33caeb900           mov dword ptr [0xb9ae3c], eax
// 0097c60a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
