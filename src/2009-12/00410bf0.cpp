// from server: 100% by auto
// roc 2009-12 00410bf0  unit: CRbxChildFrame  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00410bf0
//
// 00410bf0  8b01                 mov eax, dword ptr [ecx]
// 00410bf2  8b4904               mov ecx, dword ptr [ecx + 4]
// 00410bf5  85c0                 test eax, eax
// 00410bf7  7508                 jne 0x410c01
// 00410bf9  81f900000080         cmp ecx, 0x80000000
// 00410bff  7410                 je 0x410c11
// 00410c01  83f8ff               cmp eax, -1
// 00410c04  7508                 jne 0x410c0e
// 00410c06  81f9ffffff7f         cmp ecx, 0x7fffffff
// 00410c0c  7403                 je 0x410c11
// 00410c0e  33c0                 xor eax, eax
// 00410c10  c3                   ret 
// 00410c11  b801000000           mov eax, 1
// 00410c16  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_infinity@?$int_adapter@_J@date_time@boost@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
