// from server: 100% by auto
// roc 2009-06 00410f50  unit: CRbxChildFrame  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00410f50
//
// 00410f50  837c240400           cmp dword ptr [esp + 4], 0
// 00410f55  7510                 jne 0x410f67
// 00410f57  817c240800000080     cmp dword ptr [esp + 8], 0x80000000
// 00410f5f  7506                 jne 0x410f67
// 00410f61  b801000000           mov eax, 1
// 00410f66  c3                   ret 
// 00410f67  33c0                 xor eax, eax
// 00410f69  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_neg_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
