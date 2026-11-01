// from server: 100% by auto
// roc 2009-12 00410bb0  unit: CRbxChildFrame  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00410bb0
//
// 00410bb0  837c2404ff           cmp dword ptr [esp + 4], -1
// 00410bb5  7510                 jne 0x410bc7
// 00410bb7  817c2408ffffff7f     cmp dword ptr [esp + 8], 0x7fffffff
// 00410bbf  7506                 jne 0x410bc7
// 00410bc1  b801000000           mov eax, 1
// 00410bc6  c3                   ret 
// 00410bc7  33c0                 xor eax, eax
// 00410bc9  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_pos_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
