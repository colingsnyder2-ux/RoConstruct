// from server: 100% by auto
// roc 2007-08 00534610  unit: RBX::ScriptContext  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00534610
//
// 00534610  8b01                 mov eax, dword ptr [ecx]
// 00534612  85c0                 test eax, eax
// 00534614  8b4904               mov ecx, dword ptr [ecx + 4]
// 00534617  7508                 jne 0x534621
// 00534619  81f900000080         cmp ecx, 0x80000000
// 0053461f  7410                 je 0x534631
// 00534621  83f8ff               cmp eax, -1
// 00534624  7508                 jne 0x53462e
// 00534626  81f9ffffff7f         cmp ecx, 0x7fffffff
// 0053462c  7403                 je 0x534631
// 0053462e  33c0                 xor eax, eax
// 00534630  c3                   ret 
// 00534631  b801000000           mov eax, 1
// 00534636  c3                   ret 
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ?is_infinity@?$int_adapter@_J@date_time@boost@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
