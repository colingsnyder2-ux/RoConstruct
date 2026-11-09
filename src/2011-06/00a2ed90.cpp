// from server: 100% by auto
// roc 2011-06 00a2ed90  unit: seg_00a20000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00a2ed90
//
// 00a2ed90  e80b52e7ff           call 0x8a3fa0
// 00a2ed95  a35882d100           mov dword ptr [0xd18258], eax
// 00a2ed9a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
