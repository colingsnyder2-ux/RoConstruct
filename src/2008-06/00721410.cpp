// from server: 100% by auto
// roc 2008-06 00721410  unit: CXTPMenuBar  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00721410
//
// 00721410  51                   push ecx
// 00721411  8d442408             lea eax, [esp + 8]
// 00721415  50                   push eax
// 00721416  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0072141a  8d542404             lea edx, [esp + 4]
// 0072141e  52                   push edx
// 0072141f  50                   push eax
// 00721420  e85b6cfeff           call 0x708080
// 00721425  85c0                 test eax, eax
// 00721427  7504                 jne 0x72142d
// 00721429  59                   pop ecx
// 0072142a  c20800               ret 8
// 0072142d  8b4804               mov ecx, dword ptr [eax + 4]
// 00721430  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00721434  890a                 mov dword ptr [edx], ecx
// 00721436  b801000000           mov eax, 1
// 0072143b  59                   pop ecx
// 0072143c  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
