// from server: 100% by auto
// roc 2009-12 007f7900  unit: CPatchedControlComboBox  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f7900
//
// 007f7900  8bc1                 mov eax, ecx
// 007f7902  33c9                 xor ecx, ecx
// 007f7904  894804               mov dword ptr [eax + 4], ecx
// 007f7907  89480c               mov dword ptr [eax + 0xc], ecx
// 007f790a  894810               mov dword ptr [eax + 0x10], ecx
// 007f790d  894814               mov dword ptr [eax + 0x14], ecx
// 007f7910  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007f7914  c700f8179f00         mov dword ptr [eax], 0x9f17f8
// 007f791a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007f7921  894818               mov dword ptr [eax + 0x18], ecx
// 007f7924  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
