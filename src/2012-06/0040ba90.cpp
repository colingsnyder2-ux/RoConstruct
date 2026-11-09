// from server: 100% by auto
// roc 2012-06 0040ba90  unit: boost::exception_detail::clone_base  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040ba90
//
// 0040ba90  8b01                 mov eax, dword ptr [ecx]
// 0040ba92  8b4904               mov ecx, dword ptr [ecx + 4]
// 0040ba95  85c0                 test eax, eax
// 0040ba97  7508                 jne 0x40baa1
// 0040ba99  81f900000080         cmp ecx, 0x80000000
// 0040ba9f  7410                 je 0x40bab1
// 0040baa1  83f8ff               cmp eax, -1
// 0040baa4  7508                 jne 0x40baae
// 0040baa6  81f9ffffff7f         cmp ecx, 0x7fffffff
// 0040baac  7403                 je 0x40bab1
// 0040baae  33c0                 xor eax, eax
// 0040bab0  c3                   ret 
// 0040bab1  b801000000           mov eax, 1
// 0040bab6  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_infinity@?$int_adapter@_J@date_time@boost@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
