// from server: 100% by auto
// roc 2007-03 007762a0  unit: seg_00770000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007762a0
//
// 007762a0  e81bcfeeff           call 0x6631c0
// 007762a5  a3c4178c00           mov dword ptr [0x8c17c4], eax
// 007762aa  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
