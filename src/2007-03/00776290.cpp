// from server: 100% by auto
// roc 2007-03 00776290  unit: seg_00770000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00776290
//
// 00776290  e83b1bf2ff           call 0x697dd0
// 00776295  a3c0178c00           mov dword ptr [0x8c17c0], eax
// 0077629a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
