// from server: 100% by auto
// roc 2012-06 00b10530  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10530
//
// 00b10530  e89bbef0ff           call 0xa1c3d0
// 00b10535  a3c893e500           mov dword ptr [0xe593c8], eax
// 00b1053a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
