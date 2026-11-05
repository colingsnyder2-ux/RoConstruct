// from server: 100% by auto
// roc 2010-06 009d9550  unit: seg_009d0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009d9550
//
// 009d9550  e8cbc4e1ff           call 0x7f5a20
// 009d9555  a37455c200           mov dword ptr [0xc25574], eax
// 009d955a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
