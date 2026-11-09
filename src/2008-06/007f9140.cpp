// from server: 100% by auto
// roc 2008-06 007f9140  unit: seg_007f0000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007f9140
//
// 007f9140  e87b50efff           call 0x6ee1c0
// 007f9145  a334e09700           mov dword ptr [0x97e034], eax
// 007f914a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
