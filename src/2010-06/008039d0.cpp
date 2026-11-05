// from server: 100% by auto
// roc 2010-06 008039d0  unit: CXTPPropertyGrid  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008039d0
//
// 008039d0  51                   push ecx
// 008039d1  8d442408             lea eax, [esp + 8]
// 008039d5  50                   push eax
// 008039d6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008039da  8d542404             lea edx, [esp + 4]
// 008039de  52                   push edx
// 008039df  50                   push eax
// 008039e0  e8bb0fc3ff           call 0x4349a0
// 008039e5  85c0                 test eax, eax
// 008039e7  7504                 jne 0x8039ed
// 008039e9  59                   pop ecx
// 008039ea  c20800               ret 8
// 008039ed  8b4804               mov ecx, dword ptr [eax + 4]
// 008039f0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008039f4  890a                 mov dword ptr [edx], ecx
// 008039f6  b801000000           mov eax, 1
// 008039fb  59                   pop ecx
// 008039fc  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
