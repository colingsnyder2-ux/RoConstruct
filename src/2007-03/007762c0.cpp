// from server: 100% by auto
// roc 2007-03 007762c0  unit: seg_00770000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007762c0
//
// 007762c0  e8fbe4f1ff           call 0x6947c0
// 007762c5  a3cc178c00           mov dword ptr [0x8c17cc], eax
// 007762ca  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
