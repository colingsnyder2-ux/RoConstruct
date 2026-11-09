// from server: 100% by auto
// roc 2009-12 0097c630  unit: seg_00970000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c630
//
// 0097c630  e87b58ecff           call 0x841eb0
// 0097c635  a348aeb900           mov dword ptr [0xb9ae48], eax
// 0097c63a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
