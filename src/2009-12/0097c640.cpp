// from server: 100% by auto
// roc 2009-12 0097c640  unit: seg_00970000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c640
//
// 0097c640  e88b47f1ff           call 0x890dd0
// 0097c645  a34caeb900           mov dword ptr [0xb9ae4c], eax
// 0097c64a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
