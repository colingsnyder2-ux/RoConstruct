// from server: 100% by auto
// roc 2009-06 007211f0  unit: CPatchedControlComboBox  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007211f0
//
// 007211f0  8bc1                 mov eax, ecx
// 007211f2  33c9                 xor ecx, ecx
// 007211f4  894804               mov dword ptr [eax + 4], ecx
// 007211f7  89480c               mov dword ptr [eax + 0xc], ecx
// 007211fa  894810               mov dword ptr [eax + 0x10], ecx
// 007211fd  894814               mov dword ptr [eax + 0x14], ecx
// 00721200  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00721204  c700ac218f00         mov dword ptr [eax], 0x8f21ac
// 0072120a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00721211  894818               mov dword ptr [eax + 0x18], ecx
// 00721214  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
