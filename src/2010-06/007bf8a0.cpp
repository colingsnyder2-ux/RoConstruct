// from server: 100% by auto
// roc 2010-06 007bf8a0  unit: CXTPImageManagerResource::CBitmapDC  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bf8a0
//
// 007bf8a0  8bc1                 mov eax, ecx
// 007bf8a2  33c9                 xor ecx, ecx
// 007bf8a4  894804               mov dword ptr [eax + 4], ecx
// 007bf8a7  89480c               mov dword ptr [eax + 0xc], ecx
// 007bf8aa  894810               mov dword ptr [eax + 0x10], ecx
// 007bf8ad  894814               mov dword ptr [eax + 0x14], ecx
// 007bf8b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007bf8b4  c700f073a500         mov dword ptr [eax], 0xa573f0
// 007bf8ba  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007bf8c1  894818               mov dword ptr [eax + 0x18], ecx
// 007bf8c4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
