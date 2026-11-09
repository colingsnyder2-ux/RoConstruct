// from server: 100% by auto
// roc 2009-06 00892a30  unit: seg_00890000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00892a30
//
// 00892a30  e8dbf9f1ff           call 0x7b2410
// 00892a35  a35c19a500           mov dword ptr [0xa5195c], eax
// 00892a3a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
