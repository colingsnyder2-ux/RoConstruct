// from server: 100% by auto
// roc 2010-06 008609f0  unit: CXTPDockingPaneWindowSelect  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008609f0
//
// 008609f0  8bc1                 mov eax, ecx
// 008609f2  33c9                 xor ecx, ecx
// 008609f4  894804               mov dword ptr [eax + 4], ecx
// 008609f7  89480c               mov dword ptr [eax + 0xc], ecx
// 008609fa  894810               mov dword ptr [eax + 0x10], ecx
// 008609fd  894814               mov dword ptr [eax + 0x14], ecx
// 00860a00  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00860a04  c70044aea600         mov dword ptr [eax], 0xa6ae44
// 00860a0a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00860a11  894818               mov dword ptr [eax + 0x18], ecx
// 00860a14  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
