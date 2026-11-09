// from server: 100% by auto
// roc 2008-06 006fc290  unit: CXTPPropertyGrid  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fc290
//
// 006fc290  51                   push ecx
// 006fc291  8d442408             lea eax, [esp + 8]
// 006fc295  50                   push eax
// 006fc296  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006fc29a  8d542404             lea edx, [esp + 4]
// 006fc29e  52                   push edx
// 006fc29f  50                   push eax
// 006fc2a0  e81bc6d3ff           call 0x4388c0
// 006fc2a5  85c0                 test eax, eax
// 006fc2a7  7504                 jne 0x6fc2ad
// 006fc2a9  59                   pop ecx
// 006fc2aa  c20800               ret 8
// 006fc2ad  8b4804               mov ecx, dword ptr [eax + 4]
// 006fc2b0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006fc2b4  890a                 mov dword ptr [edx], ecx
// 006fc2b6  b801000000           mov eax, 1
// 006fc2bb  59                   pop ecx
// 006fc2bc  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
