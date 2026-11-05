// from server: 100% by auto
// roc 2007-08 00684020  unit: CXTPPropertyGrid  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00684020
//
// 00684020  8bc1                 mov eax, ecx
// 00684022  33c9                 xor ecx, ecx
// 00684024  894804               mov dword ptr [eax + 4], ecx
// 00684027  89480c               mov dword ptr [eax + 0xc], ecx
// 0068402a  894810               mov dword ptr [eax + 0x10], ecx
// 0068402d  894814               mov dword ptr [eax + 0x14], ecx
// 00684030  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00684034  c7005cd57800         mov dword ptr [eax], 0x78d55c
// 0068403a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00684041  894818               mov dword ptr [eax + 0x18], ecx
// 00684044  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
