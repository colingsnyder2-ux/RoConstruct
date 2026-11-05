// from server: 100% by auto
// roc 2010-06 00410ec0  unit: CRbxChildFrame  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00410ec0
//
// 00410ec0  8b01                 mov eax, dword ptr [ecx]
// 00410ec2  8b4904               mov ecx, dword ptr [ecx + 4]
// 00410ec5  85c0                 test eax, eax
// 00410ec7  7508                 jne 0x410ed1
// 00410ec9  81f900000080         cmp ecx, 0x80000000
// 00410ecf  7410                 je 0x410ee1
// 00410ed1  83f8ff               cmp eax, -1
// 00410ed4  7508                 jne 0x410ede
// 00410ed6  81f9ffffff7f         cmp ecx, 0x7fffffff
// 00410edc  7403                 je 0x410ee1
// 00410ede  33c0                 xor eax, eax
// 00410ee0  c3                   ret 
// 00410ee1  b801000000           mov eax, 1
// 00410ee6  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_infinity@?$int_adapter@_J@date_time@boost@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
