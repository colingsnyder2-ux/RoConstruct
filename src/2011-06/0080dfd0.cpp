// from server: 100% by auto
// roc 2011-06 0080dfd0  unit: CPatchedControlComboBox  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0080dfd0
//
// 0080dfd0  8bc1                 mov eax, ecx
// 0080dfd2  33c9                 xor ecx, ecx
// 0080dfd4  894804               mov dword ptr [eax + 4], ecx
// 0080dfd7  89480c               mov dword ptr [eax + 0xc], ecx
// 0080dfda  894810               mov dword ptr [eax + 0x10], ecx
// 0080dfdd  894814               mov dword ptr [eax + 0x14], ecx
// 0080dfe0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0080dfe4  c7004817ac00         mov dword ptr [eax], 0xac1748
// 0080dfea  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0080dff1  894818               mov dword ptr [eax + 0x18], ecx
// 0080dff4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
