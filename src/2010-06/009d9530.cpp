// from server: 100% by auto
// roc 2010-06 009d9530  unit: seg_009d0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009d9530
//
// 009d9530  e89bbcdeff           call 0x7c51d0
// 009d9535  a36c55c200           mov dword ptr [0xc2556c], eax
// 009d953a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
