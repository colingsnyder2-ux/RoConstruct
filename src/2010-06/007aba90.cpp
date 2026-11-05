// from server: 100% by auto
// roc 2010-06 007aba90  unit: CPatchedControlComboBox  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007aba90
//
// 007aba90  8bc1                 mov eax, ecx
// 007aba92  33c9                 xor ecx, ecx
// 007aba94  894804               mov dword ptr [eax + 4], ecx
// 007aba97  89480c               mov dword ptr [eax + 0xc], ecx
// 007aba9a  894810               mov dword ptr [eax + 0x10], ecx
// 007aba9d  894814               mov dword ptr [eax + 0x14], ecx
// 007abaa0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007abaa4  c700e85aa500         mov dword ptr [eax], 0xa55ae8
// 007abaaa  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007abab1  894818               mov dword ptr [eax + 0x18], ecx
// 007abab4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
