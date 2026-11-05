// from server: 100% by auto
// roc 2011-06 008a4bf0  unit: CXTPMenuBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a4bf0
//
// 008a4bf0  8bc1                 mov eax, ecx
// 008a4bf2  33c9                 xor ecx, ecx
// 008a4bf4  894804               mov dword ptr [eax + 4], ecx
// 008a4bf7  89480c               mov dword ptr [eax + 0xc], ecx
// 008a4bfa  894810               mov dword ptr [eax + 0x10], ecx
// 008a4bfd  894814               mov dword ptr [eax + 0x14], ecx
// 008a4c00  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008a4c04  c700b02ead00         mov dword ptr [eax], 0xad2eb0
// 008a4c0a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 008a4c11  894818               mov dword ptr [eax + 0x18], ecx
// 008a4c14  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
