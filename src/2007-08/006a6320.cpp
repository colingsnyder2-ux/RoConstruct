// from server: 100% by auto
// roc 2007-08 006a6320  unit: CXTPMenuBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a6320
//
// 006a6320  8bc1                 mov eax, ecx
// 006a6322  33c9                 xor ecx, ecx
// 006a6324  894804               mov dword ptr [eax + 4], ecx
// 006a6327  89480c               mov dword ptr [eax + 0xc], ecx
// 006a632a  894810               mov dword ptr [eax + 0x10], ecx
// 006a632d  894814               mov dword ptr [eax + 0x14], ecx
// 006a6330  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006a6334  c70040417d00         mov dword ptr [eax], 0x7d4140
// 006a633a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006a6341  894818               mov dword ptr [eax + 0x18], ecx
// 006a6344  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
