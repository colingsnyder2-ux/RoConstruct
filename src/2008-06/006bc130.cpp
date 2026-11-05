// from server: 100% by auto
// roc 2008-06 006bc130  unit: CXTPImageManagerResource::CBitmapDC  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006bc130
//
// 006bc130  8bc1                 mov eax, ecx
// 006bc132  33c9                 xor ecx, ecx
// 006bc134  894804               mov dword ptr [eax + 4], ecx
// 006bc137  89480c               mov dword ptr [eax + 0xc], ecx
// 006bc13a  894810               mov dword ptr [eax + 0x10], ecx
// 006bc13d  894814               mov dword ptr [eax + 0x14], ecx
// 006bc140  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006bc144  c700d8208500         mov dword ptr [eax], 0x8520d8
// 006bc14a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006bc151  894818               mov dword ptr [eax + 0x18], ecx
// 006bc154  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
