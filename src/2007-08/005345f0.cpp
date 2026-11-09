// from server: 100% by auto
// roc 2007-08 005345f0  unit: RBX::ScriptContext  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005345f0
//
// 005345f0  837c2404ff           cmp dword ptr [esp + 4], -1
// 005345f5  7510                 jne 0x534607
// 005345f7  817c2408ffffff7f     cmp dword ptr [esp + 8], 0x7fffffff
// 005345ff  7506                 jne 0x534607
// 00534601  b801000000           mov eax, 1
// 00534606  c3                   ret 
// 00534607  33c0                 xor eax, eax
// 00534609  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_pos_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
