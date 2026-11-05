// from server: 100% by auto
// roc 2009-06 00892a10  unit: seg_00890000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00892a10
//
// 00892a10  e88b41edff           call 0x766ba0
// 00892a15  a35419a500           mov dword ptr [0xa51954], eax
// 00892a1a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
