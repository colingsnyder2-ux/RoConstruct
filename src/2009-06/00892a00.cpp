// from server: 100% by auto
// roc 2009-06 00892a00  unit: seg_00890000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00892a00
//
// 00892a00  e85b30f2ff           call 0x7b5a60
// 00892a05  a35019a500           mov dword ptr [0xa51950], eax
// 00892a0a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
