// from server: 100% by auto
// roc 2008-06 00754fe0  unit: CXTPDockingPaneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00754fe0
//
// 00754fe0  8bc1                 mov eax, ecx
// 00754fe2  33c9                 xor ecx, ecx
// 00754fe4  894804               mov dword ptr [eax + 4], ecx
// 00754fe7  89480c               mov dword ptr [eax + 0xc], ecx
// 00754fea  894810               mov dword ptr [eax + 0x10], ecx
// 00754fed  894814               mov dword ptr [eax + 0x14], ecx
// 00754ff0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00754ff4  c700744e8600         mov dword ptr [eax], 0x864e74
// 00754ffa  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00755001  894818               mov dword ptr [eax + 0x18], ecx
// 00755004  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
