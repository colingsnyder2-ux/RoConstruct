// from server: 100% by auto
// roc 2007-08 006d8130  unit: CXTPDockingPaneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d8130
//
// 006d8130  8bc1                 mov eax, ecx
// 006d8132  33c9                 xor ecx, ecx
// 006d8134  894804               mov dword ptr [eax + 4], ecx
// 006d8137  89480c               mov dword ptr [eax + 0xc], ecx
// 006d813a  894810               mov dword ptr [eax + 0x10], ecx
// 006d813d  894814               mov dword ptr [eax + 0x14], ecx
// 006d8140  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006d8144  c700508c7d00         mov dword ptr [eax], 0x7d8c50
// 006d814a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006d8151  894818               mov dword ptr [eax + 0x18], ecx
// 006d8154  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
