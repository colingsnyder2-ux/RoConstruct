// from server: 100% by auto
// roc 2009-06 007358d0  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007358d0
//
// 007358d0  51                   push ecx
// 007358d1  8d442408             lea eax, [esp + 8]
// 007358d5  50                   push eax
// 007358d6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007358da  8d542404             lea edx, [esp + 4]
// 007358de  52                   push edx
// 007358df  50                   push eax
// 007358e0  e8ebcc0400           call 0x7825d0
// 007358e5  85c0                 test eax, eax
// 007358e7  7504                 jne 0x7358ed
// 007358e9  59                   pop ecx
// 007358ea  c20800               ret 8
// 007358ed  8b4804               mov ecx, dword ptr [eax + 4]
// 007358f0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007358f4  890a                 mov dword ptr [edx], ecx
// 007358f6  b801000000           mov eax, 1
// 007358fb  59                   pop ecx
// 007358fc  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
