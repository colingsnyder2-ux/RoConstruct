// from server: 100% by auto
// roc 2009-12 008330b0  unit: VCPtrList::?$CTypedPtrList  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008330b0
//
// 008330b0  8bc1                 mov eax, ecx
// 008330b2  33c9                 xor ecx, ecx
// 008330b4  894804               mov dword ptr [eax + 4], ecx
// 008330b7  89480c               mov dword ptr [eax + 0xc], ecx
// 008330ba  894810               mov dword ptr [eax + 0x10], ecx
// 008330bd  894814               mov dword ptr [eax + 0x14], ecx
// 008330c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008330c4  c70090659f00         mov dword ptr [eax], 0x9f6590
// 008330ca  c7400811000000       mov dword ptr [eax + 8], 0x11
// 008330d1  894818               mov dword ptr [eax + 0x18], ecx
// 008330d4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
