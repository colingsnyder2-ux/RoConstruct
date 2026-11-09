// from server: 100% by auto
// roc 2008-06 007f9130  unit: seg_007f0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007f9130
//
// 007f9130  e8db6ef2ff           call 0x720010
// 007f9135  a330e09700           mov dword ptr [0x97e030], eax
// 007f913a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
