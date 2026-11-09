// from server: 100% by auto
// roc 2009-06 0041c370  unit: CSettingsExplorer  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041c370
//
// 0041c370  8b01                 mov eax, dword ptr [ecx]
// 0041c372  3b442404             cmp eax, dword ptr [esp + 4]
// 0041c376  7511                 jne 0x41c389
// 0041c378  8b4904               mov ecx, dword ptr [ecx + 4]
// 0041c37b  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 0041c37f  7508                 jne 0x41c389
// 0041c381  b801000000           mov eax, 1
// 0041c386  c20800               ret 8
// 0041c389  33c0                 xor eax, eax
// 0041c38b  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ??8CPoint@@QBEHUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
