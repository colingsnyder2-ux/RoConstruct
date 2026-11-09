// from server: 100% by auto
// roc 2007-08 00776230  unit: seg_00770000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00776230
//
// 00776230  e82b88edff           call 0x64ea60
// 00776235  a3a4868c00           mov dword ptr [0x8c86a4], eax
// 0077623a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
