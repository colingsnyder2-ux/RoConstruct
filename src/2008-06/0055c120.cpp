// from server: 100% by auto
// roc 2008-06 0055c120  unit: RBX::VInstance::?$SignalDesc  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c120
//
// 0055c120  837c2404ff           cmp dword ptr [esp + 4], -1
// 0055c125  7510                 jne 0x55c137
// 0055c127  817c2408ffffff7f     cmp dword ptr [esp + 8], 0x7fffffff
// 0055c12f  7506                 jne 0x55c137
// 0055c131  b801000000           mov eax, 1
// 0055c136  c3                   ret 
// 0055c137  33c0                 xor eax, eax
// 0055c139  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_pos_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
