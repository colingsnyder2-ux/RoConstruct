// from server: 100% by auto
// roc 2007-08 00634a60  unit: MyXTPCommandBars  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00634a60
//
// 00634a60  51                   push ecx
// 00634a61  8d442408             lea eax, [esp + 8]
// 00634a65  50                   push eax
// 00634a66  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00634a6a  8d542404             lea edx, [esp + 4]
// 00634a6e  52                   push edx
// 00634a6f  50                   push eax
// 00634a70  e85b370a00           call 0x6d81d0
// 00634a75  85c0                 test eax, eax
// 00634a77  7504                 jne 0x634a7d
// 00634a79  59                   pop ecx
// 00634a7a  c20800               ret 8
// 00634a7d  8b4804               mov ecx, dword ptr [eax + 4]
// 00634a80  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00634a84  890a                 mov dword ptr [edx], ecx
// 00634a86  b801000000           mov eax, 1
// 00634a8b  59                   pop ecx
// 00634a8c  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
