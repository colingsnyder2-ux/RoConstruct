// from server: 100% by auto
// roc 2009-06 007b66b0  unit: CXTPMenuBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b66b0
//
// 007b66b0  8bc1                 mov eax, ecx
// 007b66b2  33c9                 xor ecx, ecx
// 007b66b4  894804               mov dword ptr [eax + 4], ecx
// 007b66b7  89480c               mov dword ptr [eax + 0xc], ecx
// 007b66ba  894810               mov dword ptr [eax + 0x10], ecx
// 007b66bd  894814               mov dword ptr [eax + 0x14], ecx
// 007b66c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007b66c4  c700f83a9000         mov dword ptr [eax], 0x903af8
// 007b66ca  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007b66d1  894818               mov dword ptr [eax + 0x18], ecx
// 007b66d4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
