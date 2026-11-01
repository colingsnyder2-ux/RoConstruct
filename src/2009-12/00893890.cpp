// from server: 100% by auto
// roc 2009-12 00893890  unit: CXTPMenuBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00893890
//
// 00893890  8bc1                 mov eax, ecx
// 00893892  33c9                 xor ecx, ecx
// 00893894  894804               mov dword ptr [eax + 4], ecx
// 00893897  89480c               mov dword ptr [eax + 0xc], ecx
// 0089389a  894810               mov dword ptr [eax + 0x10], ecx
// 0089389d  894814               mov dword ptr [eax + 0x14], ecx
// 008938a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008938a4  c700b041a000         mov dword ptr [eax], 0xa041b0
// 008938aa  c7400811000000       mov dword ptr [eax + 8], 0x11
// 008938b1  894818               mov dword ptr [eax + 0x18], ecx
// 008938b4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
