// from server: 100% by auto
// roc 2008-06 0055c140  unit: RBX::VInstance::?$SignalDesc  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c140
//
// 0055c140  8b01                 mov eax, dword ptr [ecx]
// 0055c142  8b4904               mov ecx, dword ptr [ecx + 4]
// 0055c145  85c0                 test eax, eax
// 0055c147  7508                 jne 0x55c151
// 0055c149  81f900000080         cmp ecx, 0x80000000
// 0055c14f  7410                 je 0x55c161
// 0055c151  83f8ff               cmp eax, -1
// 0055c154  7508                 jne 0x55c15e
// 0055c156  81f9ffffff7f         cmp ecx, 0x7fffffff
// 0055c15c  7403                 je 0x55c161
// 0055c15e  33c0                 xor eax, eax
// 0055c160  c3                   ret 
// 0055c161  b801000000           mov eax, 1
// 0055c166  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_infinity@?$int_adapter@_J@date_time@boost@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
