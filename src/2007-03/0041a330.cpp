// from server: 100% by auto
// roc 2007-03 0041a330  unit: seg_00410000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0041a330
//
// 0041a330  e86bf6ffff           call 0x4199a0
// 0041a335  a3fc548b00           mov dword ptr [0x8b54fc], eax
// 0041a33a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
