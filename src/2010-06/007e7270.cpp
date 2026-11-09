// from server: 100% by auto
// roc 2010-06 007e7270  unit: VCPtrList::?$CTypedPtrList  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7270
//
// 007e7270  8bc1                 mov eax, ecx
// 007e7272  33c9                 xor ecx, ecx
// 007e7274  894804               mov dword ptr [eax + 4], ecx
// 007e7277  89480c               mov dword ptr [eax + 0xc], ecx
// 007e727a  894810               mov dword ptr [eax + 0x10], ecx
// 007e727d  894814               mov dword ptr [eax + 0x14], ecx
// 007e7280  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007e7284  c70078a8a500         mov dword ptr [eax], 0xa5a878
// 007e728a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007e7291  894818               mov dword ptr [eax + 0x18], ecx
// 007e7294  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
