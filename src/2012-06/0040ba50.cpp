// from server: 100% by auto
// roc 2012-06 0040ba50  unit: boost::exception_detail::clone_base  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040ba50
//
// 0040ba50  837c2404ff           cmp dword ptr [esp + 4], -1
// 0040ba55  7510                 jne 0x40ba67
// 0040ba57  817c2408ffffff7f     cmp dword ptr [esp + 8], 0x7fffffff
// 0040ba5f  7506                 jne 0x40ba67
// 0040ba61  b801000000           mov eax, 1
// 0040ba66  c3                   ret 
// 0040ba67  33c0                 xor eax, eax
// 0040ba69  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_pos_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
