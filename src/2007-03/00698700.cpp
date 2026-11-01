// from server: 100% by auto
// roc 2007-03 00698700  unit: seg_00690000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00698700
//
// 00698700  8bc1                 mov eax, ecx
// 00698702  33c9                 xor ecx, ecx
// 00698704  894804               mov dword ptr [eax + 4], ecx
// 00698707  89480c               mov dword ptr [eax + 0xc], ecx
// 0069870a  894810               mov dword ptr [eax + 0x10], ecx
// 0069870d  894814               mov dword ptr [eax + 0x14], ecx
// 00698710  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00698714  c700301a7d00         mov dword ptr [eax], 0x7d1a30
// 0069871a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00698721  894818               mov dword ptr [eax + 0x18], ecx
// 00698724  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
