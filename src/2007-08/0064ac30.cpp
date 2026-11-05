// from server: 100% by auto
// roc 2007-08 0064ac30  unit: CXTPCommandBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0064ac30
//
// 0064ac30  8bc1                 mov eax, ecx
// 0064ac32  33c9                 xor ecx, ecx
// 0064ac34  894804               mov dword ptr [eax + 4], ecx
// 0064ac37  89480c               mov dword ptr [eax + 0xc], ecx
// 0064ac3a  894810               mov dword ptr [eax + 0x10], ecx
// 0064ac3d  894814               mov dword ptr [eax + 0x14], ecx
// 0064ac40  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0064ac44  c700586c7c00         mov dword ptr [eax], 0x7c6c58
// 0064ac4a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0064ac51  894818               mov dword ptr [eax + 0x18], ecx
// 0064ac54  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
