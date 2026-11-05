// from server: 100% by auto
// roc 2009-06 00758230  unit: VCPtrList::?$CTypedPtrList  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758230
//
// 00758230  8bc1                 mov eax, ecx
// 00758232  33c9                 xor ecx, ecx
// 00758234  894804               mov dword ptr [eax + 4], ecx
// 00758237  89480c               mov dword ptr [eax + 0xc], ecx
// 0075823a  894810               mov dword ptr [eax + 0x10], ecx
// 0075823d  894814               mov dword ptr [eax + 0x14], ecx
// 00758240  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00758244  c700e8608f00         mov dword ptr [eax], 0x8f60e8
// 0075824a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00758251  894818               mov dword ptr [eax + 0x18], ecx
// 00758254  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
