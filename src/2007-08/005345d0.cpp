// from server: 100% by auto
// roc 2007-08 005345d0  unit: RBX::ScriptContext  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005345d0
//
// 005345d0  837c240400           cmp dword ptr [esp + 4], 0
// 005345d5  7510                 jne 0x5345e7
// 005345d7  817c240800000080     cmp dword ptr [esp + 8], 0x80000000
// 005345df  7506                 jne 0x5345e7
// 005345e1  b801000000           mov eax, 1
// 005345e6  c3                   ret 
// 005345e7  33c0                 xor eax, eax
// 005345e9  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_neg_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
