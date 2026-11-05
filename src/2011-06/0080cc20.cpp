// from server: 100% by auto
// roc 2011-06 0080cc20  unit: CPatchedControlComboBox  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0080cc20
//
// 0080cc20  8b01                 mov eax, dword ptr [ecx]
// 0080cc22  3b442404             cmp eax, dword ptr [esp + 4]
// 0080cc26  750e                 jne 0x80cc36
// 0080cc28  8b4904               mov ecx, dword ptr [ecx + 4]
// 0080cc2b  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 0080cc2f  7505                 jne 0x80cc36
// 0080cc31  33c0                 xor eax, eax
// 0080cc33  c20800               ret 8
// 0080cc36  b801000000           mov eax, 1
// 0080cc3b  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcustomizebutton.cpp (function ??9CSize@@QBEHUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcustomizebutton.cpp
