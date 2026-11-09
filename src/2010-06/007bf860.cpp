// from server: 100% by auto
// roc 2010-06 007bf860  unit: CXTPImageManagerResource::CBitmapDC  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bf860
//
// 007bf860  8bc1                 mov eax, ecx
// 007bf862  33c9                 xor ecx, ecx
// 007bf864  894804               mov dword ptr [eax + 4], ecx
// 007bf867  89480c               mov dword ptr [eax + 0xc], ecx
// 007bf86a  894810               mov dword ptr [eax + 0x10], ecx
// 007bf86d  894814               mov dword ptr [eax + 0x14], ecx
// 007bf870  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007bf874  c700d873a500         mov dword ptr [eax], 0xa573d8
// 007bf87a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007bf881  894818               mov dword ptr [eax + 0x18], ecx
// 007bf884  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
