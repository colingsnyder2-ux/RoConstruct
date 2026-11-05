// from server: 100% by auto
// roc 2008-06 006ab780  unit: CPatchedControlComboBox  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ab780
//
// 006ab780  8b01                 mov eax, dword ptr [ecx]
// 006ab782  3b442404             cmp eax, dword ptr [esp + 4]
// 006ab786  750e                 jne 0x6ab796
// 006ab788  8b4904               mov ecx, dword ptr [ecx + 4]
// 006ab78b  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 006ab78f  7505                 jne 0x6ab796
// 006ab791  33c0                 xor eax, eax
// 006ab793  c20800               ret 8
// 006ab796  b801000000           mov eax, 1
// 006ab79b  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcustomizebutton.cpp (function ??9CSize@@QBEHUtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcustomizebutton.cpp
