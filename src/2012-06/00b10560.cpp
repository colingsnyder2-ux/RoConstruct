// from server: 100% by auto
// roc 2012-06 00b10560  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10560
//
// 00b10560  e87ba0f0ff           call 0xa1a5e0
// 00b10565  a3d493e500           mov dword ptr [0xe593d4], eax
// 00b1056a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
