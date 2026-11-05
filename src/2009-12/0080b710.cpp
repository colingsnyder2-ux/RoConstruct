// from server: 100% by auto
// roc 2009-12 0080b710  unit: CXTPImageManagerResource::CBitmapDC  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080b710
//
// 0080b710  8bc1                 mov eax, ecx
// 0080b712  33c9                 xor ecx, ecx
// 0080b714  894804               mov dword ptr [eax + 4], ecx
// 0080b717  89480c               mov dword ptr [eax + 0xc], ecx
// 0080b71a  894810               mov dword ptr [eax + 0x10], ecx
// 0080b71d  894814               mov dword ptr [eax + 0x14], ecx
// 0080b720  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0080b724  c700f0309f00         mov dword ptr [eax], 0x9f30f0
// 0080b72a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0080b731  894818               mov dword ptr [eax + 0x18], ecx
// 0080b734  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
