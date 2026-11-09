// from server: 100% by auto
// roc 2008-06 006dd960  unit: VCPtrList::?$CTypedPtrList  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006dd960
//
// 006dd960  8bc1                 mov eax, ecx
// 006dd962  33c9                 xor ecx, ecx
// 006dd964  894804               mov dword ptr [eax + 4], ecx
// 006dd967  89480c               mov dword ptr [eax + 0xc], ecx
// 006dd96a  894810               mov dword ptr [eax + 0x10], ecx
// 006dd96d  894814               mov dword ptr [eax + 0x14], ecx
// 006dd970  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006dd974  c7005c5d8500         mov dword ptr [eax], 0x855d5c
// 006dd97a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006dd981  894818               mov dword ptr [eax + 0x18], ecx
// 006dd984  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
