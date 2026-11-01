// from server: 100% by auto
// roc 2007-03 006d6320  unit: seg_006d0000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006d6320
//
// 006d6320  8bc1                 mov eax, ecx
// 006d6322  33c9                 xor ecx, ecx
// 006d6324  894804               mov dword ptr [eax + 4], ecx
// 006d6327  89480c               mov dword ptr [eax + 0xc], ecx
// 006d632a  894810               mov dword ptr [eax + 0x10], ecx
// 006d632d  894814               mov dword ptr [eax + 0x14], ecx
// 006d6330  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006d6334  c700247c7d00         mov dword ptr [eax], 0x7d7c24
// 006d633a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006d6341  894818               mov dword ptr [eax + 0x18], ecx
// 006d6344  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
