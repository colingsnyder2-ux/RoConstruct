// from server: 100% by auto
// roc 2011-06 0040a380  unit: boost::exception_detail::clone_base  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040a380
//
// 0040a380  8b01                 mov eax, dword ptr [ecx]
// 0040a382  8b4904               mov ecx, dword ptr [ecx + 4]
// 0040a385  85c0                 test eax, eax
// 0040a387  7508                 jne 0x40a391
// 0040a389  81f900000080         cmp ecx, 0x80000000
// 0040a38f  7410                 je 0x40a3a1
// 0040a391  83f8ff               cmp eax, -1
// 0040a394  7508                 jne 0x40a39e
// 0040a396  81f9ffffff7f         cmp ecx, 0x7fffffff
// 0040a39c  7403                 je 0x40a3a1
// 0040a39e  33c0                 xor eax, eax
// 0040a3a0  c3                   ret 
// 0040a3a1  b801000000           mov eax, 1
// 0040a3a6  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_infinity@?$int_adapter@_J@date_time@boost@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
