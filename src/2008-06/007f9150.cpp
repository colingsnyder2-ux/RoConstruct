// from server: 100% by auto
// roc 2008-06 007f9150  unit: seg_007f0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007f9150
//
// 007f9150  e8bb55efff           call 0x6ee710
// 007f9155  a338e09700           mov dword ptr [0x97e038], eax
// 007f915a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
