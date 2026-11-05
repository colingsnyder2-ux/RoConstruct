// from server: 100% by auto
// roc 2008-06 00720c50  unit: CXTPMenuBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00720c50
//
// 00720c50  8bc1                 mov eax, ecx
// 00720c52  33c9                 xor ecx, ecx
// 00720c54  894804               mov dword ptr [eax + 4], ecx
// 00720c57  89480c               mov dword ptr [eax + 0xc], ecx
// 00720c5a  894810               mov dword ptr [eax + 0x10], ecx
// 00720c5d  894814               mov dword ptr [eax + 0x14], ecx
// 00720c60  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00720c64  c70000068600         mov dword ptr [eax], 0x860600
// 00720c6a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00720c71  894818               mov dword ptr [eax + 0x18], ecx
// 00720c74  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
