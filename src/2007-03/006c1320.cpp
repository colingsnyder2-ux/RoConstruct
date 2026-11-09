// from server: 100% by auto
// roc 2007-03 006c1320  unit: seg_006c0000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c1320
//
// 006c1320  8bc1                 mov eax, ecx
// 006c1322  33c9                 xor ecx, ecx
// 006c1324  894804               mov dword ptr [eax + 4], ecx
// 006c1327  89480c               mov dword ptr [eax + 0xc], ecx
// 006c132a  894810               mov dword ptr [eax + 0x10], ecx
// 006c132d  894814               mov dword ptr [eax + 0x14], ecx
// 006c1330  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006c1334  c700a8597d00         mov dword ptr [eax], 0x7d59a8
// 006c133a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006c1341  894818               mov dword ptr [eax + 0x18], ecx
// 006c1344  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
