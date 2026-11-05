// from server: 100% by auto
// roc 2011-06 008bdcf0  unit: CXTPDockingPaneWindowSelect  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bdcf0
//
// 008bdcf0  8bc1                 mov eax, ecx
// 008bdcf2  33c9                 xor ecx, ecx
// 008bdcf4  894804               mov dword ptr [eax + 4], ecx
// 008bdcf7  89480c               mov dword ptr [eax + 0xc], ecx
// 008bdcfa  894810               mov dword ptr [eax + 0x10], ecx
// 008bdcfd  894814               mov dword ptr [eax + 0x14], ecx
// 008bdd00  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008bdd04  c7005458ad00         mov dword ptr [eax], 0xad5854
// 008bdd0a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 008bdd11  894818               mov dword ptr [eax + 0x18], ecx
// 008bdd14  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
