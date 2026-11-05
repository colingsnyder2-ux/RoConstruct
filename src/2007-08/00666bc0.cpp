// from server: 100% by auto
// roc 2007-08 00666bc0  unit: VCPtrList::?$CTypedPtrList  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00666bc0
//
// 00666bc0  8bc1                 mov eax, ecx
// 00666bc2  33c9                 xor ecx, ecx
// 00666bc4  894804               mov dword ptr [eax + 4], ecx
// 00666bc7  89480c               mov dword ptr [eax + 0xc], ecx
// 00666bca  894810               mov dword ptr [eax + 0x10], ecx
// 00666bcd  894814               mov dword ptr [eax + 0x14], ecx
// 00666bd0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00666bd4  c700e4a57c00         mov dword ptr [eax], 0x7ca5e4
// 00666bda  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00666be1  894818               mov dword ptr [eax + 0x18], ecx
// 00666be4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
