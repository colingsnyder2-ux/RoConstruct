// from server: 100% by auto
// roc 2011-06 0040a340  unit: boost::exception_detail::clone_base  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040a340
//
// 0040a340  837c2404ff           cmp dword ptr [esp + 4], -1
// 0040a345  7510                 jne 0x40a357
// 0040a347  817c2408ffffff7f     cmp dword ptr [esp + 8], 0x7fffffff
// 0040a34f  7506                 jne 0x40a357
// 0040a351  b801000000           mov eax, 1
// 0040a356  c3                   ret 
// 0040a357  33c0                 xor eax, eax
// 0040a359  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_pos_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
