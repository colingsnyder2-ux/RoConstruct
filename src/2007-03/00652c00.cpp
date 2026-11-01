// from server: 100% by auto
// roc 2007-03 00652c00  unit: seg_00650000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00652c00
//
// 00652c00  8bc1                 mov eax, ecx
// 00652c02  33c9                 xor ecx, ecx
// 00652c04  894804               mov dword ptr [eax + 4], ecx
// 00652c07  89480c               mov dword ptr [eax + 0xc], ecx
// 00652c0a  894810               mov dword ptr [eax + 0x10], ecx
// 00652c0d  894814               mov dword ptr [eax + 0x14], ecx
// 00652c10  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00652c14  c70044767c00         mov dword ptr [eax], 0x7c7644
// 00652c1a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00652c21  894818               mov dword ptr [eax + 0x18], ecx
// 00652c24  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
