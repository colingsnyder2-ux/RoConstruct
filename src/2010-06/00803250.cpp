// from server: 100% by auto
// roc 2010-06 00803250  unit: CXTPPropertyGrid  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00803250
//
// 00803250  8bc1                 mov eax, ecx
// 00803252  33c9                 xor ecx, ecx
// 00803254  894804               mov dword ptr [eax + 4], ecx
// 00803257  89480c               mov dword ptr [eax + 0xc], ecx
// 0080325a  894810               mov dword ptr [eax + 0x10], ecx
// 0080325d  894814               mov dword ptr [eax + 0x14], ecx
// 00803260  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00803264  c7003078a000         mov dword ptr [eax], 0xa07830
// 0080326a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00803271  894818               mov dword ptr [eax + 0x18], ecx
// 00803274  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
