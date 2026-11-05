// from server: 100% by auto
// roc 2012-06 00b10520  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10520
//
// 00b10520  e8fbede8ff           call 0x99f320
// 00b10525  a3c493e500           mov dword ptr [0xe593c4], eax
// 00b1052a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
