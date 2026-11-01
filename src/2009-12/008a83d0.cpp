// from server: 100% by auto
// roc 2009-12 008a83d0  unit: CXTPDockingPaneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a83d0
//
// 008a83d0  8bc1                 mov eax, ecx
// 008a83d2  33c9                 xor ecx, ecx
// 008a83d4  894804               mov dword ptr [eax + 4], ecx
// 008a83d7  89480c               mov dword ptr [eax + 0xc], ecx
// 008a83da  894810               mov dword ptr [eax + 0x10], ecx
// 008a83dd  894814               mov dword ptr [eax + 0x14], ecx
// 008a83e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008a83e4  c7002c63a000         mov dword ptr [eax], 0xa0632c
// 008a83ea  c7400811000000       mov dword ptr [eax + 8], 0x11
// 008a83f1  894818               mov dword ptr [eax + 0x18], ecx
// 008a83f4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
