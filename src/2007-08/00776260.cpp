// from server: 100% by auto
// roc 2007-08 00776260  unit: seg_00770000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00776260
//
// 00776260  e85b16f0ff           call 0x6778c0
// 00776265  a3b0868c00           mov dword ptr [0x8c86b0], eax
// 0077626a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
