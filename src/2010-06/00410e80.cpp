// from server: 100% by auto
// roc 2010-06 00410e80  unit: CRbxChildFrame  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00410e80
//
// 00410e80  837c2404ff           cmp dword ptr [esp + 4], -1
// 00410e85  7510                 jne 0x410e97
// 00410e87  817c2408ffffff7f     cmp dword ptr [esp + 8], 0x7fffffff
// 00410e8f  7506                 jne 0x410e97
// 00410e91  b801000000           mov eax, 1
// 00410e96  c3                   ret 
// 00410e97  33c0                 xor eax, eax
// 00410e99  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_pos_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
