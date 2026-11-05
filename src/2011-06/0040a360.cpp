// from server: 100% by auto
// roc 2011-06 0040a360  unit: boost::exception_detail::clone_base  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040a360
//
// 0040a360  837c240400           cmp dword ptr [esp + 4], 0
// 0040a365  7510                 jne 0x40a377
// 0040a367  817c240800000080     cmp dword ptr [esp + 8], 0x80000000
// 0040a36f  7506                 jne 0x40a377
// 0040a371  b801000000           mov eax, 1
// 0040a376  c3                   ret 
// 0040a377  33c0                 xor eax, eax
// 0040a379  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_neg_inf@?$int_adapter@_J@date_time@boost@@SA_N_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
