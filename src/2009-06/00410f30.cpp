// from server: 100% by auto
// roc 2009-06 00410f30  unit: CRbxChildFrame  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00410f30
//
// 00410f30  837c2404ff           cmp dword ptr [esp + 4], -1
// 00410f35  7510                 jne 0x410f47
// 00410f37  817c2408ffffff7f     cmp dword ptr [esp + 8], 0x7fffffff
// 00410f3f  7506                 jne 0x410f47
// 00410f41  b801000000           mov eax, 1
// 00410f46  c3                   ret 
// 00410f47  33c0                 xor eax, eax
// 00410f49  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_pos_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
