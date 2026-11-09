// from server: 100% by auto
// roc 2009-12 0041c9e0  unit: CSettingsExplorer  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041c9e0
//
// 0041c9e0  8b01                 mov eax, dword ptr [ecx]
// 0041c9e2  3b442404             cmp eax, dword ptr [esp + 4]
// 0041c9e6  7511                 jne 0x41c9f9
// 0041c9e8  8b4904               mov ecx, dword ptr [ecx + 4]
// 0041c9eb  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 0041c9ef  7508                 jne 0x41c9f9
// 0041c9f1  b801000000           mov eax, 1
// 0041c9f6  c20800               ret 8
// 0041c9f9  33c0                 xor eax, eax
// 0041c9fb  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\bartool.cpp (function ??8CSize@@QBEHUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bartool.cpp
