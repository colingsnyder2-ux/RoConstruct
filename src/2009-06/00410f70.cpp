// from server: 100% by auto
// roc 2009-06 00410f70  unit: CRbxChildFrame  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00410f70
//
// 00410f70  8b01                 mov eax, dword ptr [ecx]
// 00410f72  8b4904               mov ecx, dword ptr [ecx + 4]
// 00410f75  85c0                 test eax, eax
// 00410f77  7508                 jne 0x410f81
// 00410f79  81f900000080         cmp ecx, 0x80000000
// 00410f7f  7410                 je 0x410f91
// 00410f81  83f8ff               cmp eax, -1
// 00410f84  7508                 jne 0x410f8e
// 00410f86  81f9ffffff7f         cmp ecx, 0x7fffffff
// 00410f8c  7403                 je 0x410f91
// 00410f8e  33c0                 xor eax, eax
// 00410f90  c3                   ret 
// 00410f91  b801000000           mov eax, 1
// 00410f96  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_infinity@?$int_adapter@_J@date_time@boost@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
