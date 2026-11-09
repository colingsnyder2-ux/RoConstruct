// from server: 100% by auto
// roc 2007-08 006dc6f0  unit: CXTPDockingPaneWindowSelect  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006dc6f0
//
// 006dc6f0  8bc1                 mov eax, ecx
// 006dc6f2  33c9                 xor ecx, ecx
// 006dc6f4  894804               mov dword ptr [eax + 4], ecx
// 006dc6f7  89480c               mov dword ptr [eax + 0xc], ecx
// 006dc6fa  894810               mov dword ptr [eax + 0x10], ecx
// 006dc6fd  894814               mov dword ptr [eax + 0x14], ecx
// 006dc700  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006dc704  c70054947d00         mov dword ptr [eax], 0x7d9454
// 006dc70a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006dc711  894818               mov dword ptr [eax + 0x18], ecx
// 006dc714  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
