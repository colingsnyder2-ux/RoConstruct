// from server: 100% by auto
// roc 2008-06 007f9160  unit: seg_007f0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007f9160
//
// 007f9160  e8ab15f2ff           call 0x71a710
// 007f9165  a33ce09700           mov dword ptr [0x97e03c], eax
// 007f916a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
