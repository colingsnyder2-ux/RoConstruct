// from server: 100% by auto
// roc 2008-06 00754fa0  unit: CXTPDockingPaneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00754fa0
//
// 00754fa0  8bc1                 mov eax, ecx
// 00754fa2  33c9                 xor ecx, ecx
// 00754fa4  894804               mov dword ptr [eax + 4], ecx
// 00754fa7  89480c               mov dword ptr [eax + 0xc], ecx
// 00754faa  894810               mov dword ptr [eax + 0x10], ecx
// 00754fad  894814               mov dword ptr [eax + 0x14], ecx
// 00754fb0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00754fb4  c7005c4e8600         mov dword ptr [eax], 0x864e5c
// 00754fba  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00754fc1  894818               mov dword ptr [eax + 0x18], ecx
// 00754fc4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
