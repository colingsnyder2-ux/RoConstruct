// from server: 100% by auto
// roc 2010-06 007aa650  unit: CPatchedControlComboBox  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007aa650
//
// 007aa650  8b01                 mov eax, dword ptr [ecx]
// 007aa652  3b442404             cmp eax, dword ptr [esp + 4]
// 007aa656  750e                 jne 0x7aa666
// 007aa658  8b4904               mov ecx, dword ptr [ecx + 4]
// 007aa65b  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 007aa65f  7505                 jne 0x7aa666
// 007aa661  33c0                 xor eax, eax
// 007aa663  c20800               ret 8
// 007aa666  b801000000           mov eax, 1
// 007aa66b  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcustomizebutton.cpp (function ??9CSize@@QBEHUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcustomizebutton.cpp
