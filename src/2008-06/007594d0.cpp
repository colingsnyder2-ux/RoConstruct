// from server: 100% by auto
// roc 2008-06 007594d0  unit: CXTPDockingPaneWindowSelect  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007594d0
//
// 007594d0  8bc1                 mov eax, ecx
// 007594d2  33c9                 xor ecx, ecx
// 007594d4  894804               mov dword ptr [eax + 4], ecx
// 007594d7  89480c               mov dword ptr [eax + 0xc], ecx
// 007594da  894810               mov dword ptr [eax + 0x10], ecx
// 007594dd  894814               mov dword ptr [eax + 0x14], ecx
// 007594e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007594e4  c700b4568600         mov dword ptr [eax], 0x8656b4
// 007594ea  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007594f1  894818               mov dword ptr [eax + 0x18], ecx
// 007594f4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
