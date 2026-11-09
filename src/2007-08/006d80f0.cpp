// from server: 100% by auto
// roc 2007-08 006d80f0  unit: CXTPDockingPaneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006d80f0
//
// 006d80f0  8bc1                 mov eax, ecx
// 006d80f2  33c9                 xor ecx, ecx
// 006d80f4  894804               mov dword ptr [eax + 4], ecx
// 006d80f7  89480c               mov dword ptr [eax + 0xc], ecx
// 006d80fa  894810               mov dword ptr [eax + 0x10], ecx
// 006d80fd  894814               mov dword ptr [eax + 0x14], ecx
// 006d8100  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006d8104  c700388c7d00         mov dword ptr [eax], 0x7d8c38
// 006d810a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006d8111  894818               mov dword ptr [eax + 0x18], ecx
// 006d8114  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
