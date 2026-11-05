// from server: 100% by auto
// roc 2009-06 008929f0  unit: seg_00890000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008929f0
//
// 008929f0  e85b76eaff           call 0x73a050
// 008929f5  a34c19a500           mov dword ptr [0xa5194c], eax
// 008929fa  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
