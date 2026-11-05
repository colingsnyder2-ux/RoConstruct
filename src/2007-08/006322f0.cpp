// from server: 100% by auto
// roc 2007-08 006322f0  unit: CRobloxControlColorSelector  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006322f0
//
// 006322f0  8bc1                 mov eax, ecx
// 006322f2  33c9                 xor ecx, ecx
// 006322f4  894804               mov dword ptr [eax + 4], ecx
// 006322f7  89480c               mov dword ptr [eax + 0xc], ecx
// 006322fa  894810               mov dword ptr [eax + 0x10], ecx
// 006322fd  894814               mov dword ptr [eax + 0x14], ecx
// 00632300  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00632304  c700004f7c00         mov dword ptr [eax], 0x7c4f00
// 0063230a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00632311  894818               mov dword ptr [eax + 0x18], ecx
// 00632314  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
