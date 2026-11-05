// from server: 100% by auto
// roc 2009-06 007346b0  unit: CXTPImageManagerResource::CBitmapDC  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007346b0
//
// 007346b0  8bc1                 mov eax, ecx
// 007346b2  33c9                 xor ecx, ecx
// 007346b4  894804               mov dword ptr [eax + 4], ecx
// 007346b7  89480c               mov dword ptr [eax + 0xc], ecx
// 007346ba  894810               mov dword ptr [eax + 0x10], ecx
// 007346bd  894814               mov dword ptr [eax + 0x14], ecx
// 007346c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007346c4  c70038318f00         mov dword ptr [eax], 0x8f3138
// 007346ca  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007346d1  894818               mov dword ptr [eax + 0x18], ecx
// 007346d4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
