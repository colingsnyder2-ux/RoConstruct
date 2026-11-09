// from server: 100% by auto
// roc 2007-08 0064ac70  unit: CXTPCommandBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0064ac70
//
// 0064ac70  8bc1                 mov eax, ecx
// 0064ac72  33c9                 xor ecx, ecx
// 0064ac74  894804               mov dword ptr [eax + 4], ecx
// 0064ac77  89480c               mov dword ptr [eax + 0xc], ecx
// 0064ac7a  894810               mov dword ptr [eax + 0x10], ecx
// 0064ac7d  894814               mov dword ptr [eax + 0x14], ecx
// 0064ac80  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0064ac84  c700706c7c00         mov dword ptr [eax], 0x7c6c70
// 0064ac8a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0064ac91  894818               mov dword ptr [eax + 0x18], ecx
// 0064ac94  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
