// from server: 100% by auto
// roc 2007-03 00632aa0  unit: seg_00630000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00632aa0
//
// 00632aa0  8b01                 mov eax, dword ptr [ecx]
// 00632aa2  3b442404             cmp eax, dword ptr [esp + 4]
// 00632aa6  750e                 jne 0x632ab6
// 00632aa8  8b4904               mov ecx, dword ptr [ecx + 4]
// 00632aab  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 00632aaf  7505                 jne 0x632ab6
// 00632ab1  33c0                 xor eax, eax
// 00632ab3  c20800               ret 8
// 00632ab6  b801000000           mov eax, 1
// 00632abb  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??9CSize@@QBEHUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
