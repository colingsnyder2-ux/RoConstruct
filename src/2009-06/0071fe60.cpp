// from server: 100% by auto
// roc 2009-06 0071fe60  unit: CPatchedControlComboBox  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071fe60
//
// 0071fe60  8b01                 mov eax, dword ptr [ecx]
// 0071fe62  3b442404             cmp eax, dword ptr [esp + 4]
// 0071fe66  750e                 jne 0x71fe76
// 0071fe68  8b4904               mov ecx, dword ptr [ecx + 4]
// 0071fe6b  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 0071fe6f  7505                 jne 0x71fe76
// 0071fe71  33c0                 xor eax, eax
// 0071fe73  c20800               ret 8
// 0071fe76  b801000000           mov eax, 1
// 0071fe7b  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcustomizebutton.cpp (function ??9CSize@@QBEHUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcustomizebutton.cpp
