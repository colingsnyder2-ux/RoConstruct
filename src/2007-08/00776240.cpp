// from server: 100% by auto
// roc 2007-08 00776240  unit: seg_00770000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00776240
//
// 00776240  e84bf7f2ff           call 0x6a5990
// 00776245  a3a8868c00           mov dword ptr [0x8c86a8], eax
// 0077624a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
