// from server: 100% by auto
// roc 2011-06 004260a0  unit: CInstanceExplorer  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004260a0
//
// 004260a0  8b01                 mov eax, dword ptr [ecx]
// 004260a2  3b442404             cmp eax, dword ptr [esp + 4]
// 004260a6  7511                 jne 0x4260b9
// 004260a8  8b4904               mov ecx, dword ptr [ecx + 4]
// 004260ab  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 004260af  7508                 jne 0x4260b9
// 004260b1  b801000000           mov eax, 1
// 004260b6  c20800               ret 8
// 004260b9  33c0                 xor eax, eax
// 004260bb  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ??8CPoint@@QBEHUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
