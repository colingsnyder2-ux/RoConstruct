// from server: 100% by auto
// roc 2007-08 006ed5a0  unit: CXTPDockingPaneContext  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006ed5a0
//
// 006ed5a0  8bc1                 mov eax, ecx
// 006ed5a2  33c9                 xor ecx, ecx
// 006ed5a4  894804               mov dword ptr [eax + 4], ecx
// 006ed5a7  89480c               mov dword ptr [eax + 0xc], ecx
// 006ed5aa  894810               mov dword ptr [eax + 0x10], ecx
// 006ed5ad  894814               mov dword ptr [eax + 0x14], ecx
// 006ed5b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006ed5b4  c70024af7d00         mov dword ptr [eax], 0x7daf24
// 006ed5ba  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006ed5c1  894818               mov dword ptr [eax + 0x18], ecx
// 006ed5c4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
