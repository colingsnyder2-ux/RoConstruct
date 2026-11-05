// from server: 100% by auto
// roc 2007-08 0064f130  unit: CXTPToolBar  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0064f130
//
// 0064f130  8b01                 mov eax, dword ptr [ecx]
// 0064f132  3b442404             cmp eax, dword ptr [esp + 4]
// 0064f136  750e                 jne 0x64f146
// 0064f138  8b4904               mov ecx, dword ptr [ecx + 4]
// 0064f13b  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 0064f13f  7505                 jne 0x64f146
// 0064f141  33c0                 xor eax, eax
// 0064f143  c20800               ret 8
// 0064f146  b801000000           mov eax, 1
// 0064f14b  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ??9CSize@@QBEHUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
