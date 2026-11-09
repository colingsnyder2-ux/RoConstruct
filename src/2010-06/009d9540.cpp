// from server: 100% by auto
// roc 2010-06 009d9540  unit: seg_009d0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009d9540
//
// 009d9540  e8bbd8e6ff           call 0x846e00
// 009d9545  a37055c200           mov dword ptr [0xc25570], eax
// 009d954a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
