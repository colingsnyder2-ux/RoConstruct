// from server: 100% by auto
// roc 2008-06 00421e80  unit: CSettingsExplorer  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00421e80
//
// 00421e80  8b01                 mov eax, dword ptr [ecx]
// 00421e82  3b442404             cmp eax, dword ptr [esp + 4]
// 00421e86  7511                 jne 0x421e99
// 00421e88  8b4904               mov ecx, dword ptr [ecx + 4]
// 00421e8b  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 00421e8f  7508                 jne 0x421e99
// 00421e91  b801000000           mov eax, 1
// 00421e96  c20800               ret 8
// 00421e99  33c0                 xor eax, eax
// 00421e9b  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ??8CPoint@@QBEHUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
