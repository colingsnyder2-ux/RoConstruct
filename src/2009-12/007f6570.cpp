// from server: 100% by auto
// roc 2009-12 007f6570  unit: CXTPPropertyGridItem  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f6570
//
// 007f6570  8b01                 mov eax, dword ptr [ecx]
// 007f6572  3b442404             cmp eax, dword ptr [esp + 4]
// 007f6576  750e                 jne 0x7f6586
// 007f6578  8b4904               mov ecx, dword ptr [ecx + 4]
// 007f657b  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 007f657f  7505                 jne 0x7f6586
// 007f6581  33c0                 xor eax, eax
// 007f6583  c20800               ret 8
// 007f6586  b801000000           mov eax, 1
// 007f658b  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??9CSize@@QBEHUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
