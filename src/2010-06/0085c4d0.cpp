// from server: 100% by auto
// roc 2010-06 0085c4d0  unit: CXTPDockingPaneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085c4d0
//
// 0085c4d0  8bc1                 mov eax, ecx
// 0085c4d2  33c9                 xor ecx, ecx
// 0085c4d4  894804               mov dword ptr [eax + 4], ecx
// 0085c4d7  89480c               mov dword ptr [eax + 0xc], ecx
// 0085c4da  894810               mov dword ptr [eax + 0x10], ecx
// 0085c4dd  894814               mov dword ptr [eax + 0x14], ecx
// 0085c4e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0085c4e4  c700fca5a600         mov dword ptr [eax], 0xa6a5fc
// 0085c4ea  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0085c4f1  894818               mov dword ptr [eax + 0x18], ecx
// 0085c4f4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
