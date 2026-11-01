// from server: 100% by auto
// roc 2009-12 0080b7d0  unit: CXTPImageManagerResource::CBitmapDC  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080b7d0
//
// 0080b7d0  8bc1                 mov eax, ecx
// 0080b7d2  33c9                 xor ecx, ecx
// 0080b7d4  894804               mov dword ptr [eax + 4], ecx
// 0080b7d7  89480c               mov dword ptr [eax + 0xc], ecx
// 0080b7da  894810               mov dword ptr [eax + 0x10], ecx
// 0080b7dd  894814               mov dword ptr [eax + 0x14], ecx
// 0080b7e0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0080b7e4  c70038319f00         mov dword ptr [eax], 0x9f3138
// 0080b7ea  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0080b7f1  894818               mov dword ptr [eax + 0x18], ecx
// 0080b7f4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
