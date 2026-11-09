// from server: 100% by auto
// roc 2007-03 00680a90  unit: seg_00680000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00680a90
//
// 00680a90  8bc1                 mov eax, ecx
// 00680a92  33c9                 xor ecx, ecx
// 00680a94  894804               mov dword ptr [eax + 4], ecx
// 00680a97  89480c               mov dword ptr [eax + 0xc], ecx
// 00680a9a  894810               mov dword ptr [eax + 0x10], ecx
// 00680a9d  894814               mov dword ptr [eax + 0x14], ecx
// 00680aa0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00680aa4  c70018e27c00         mov dword ptr [eax], 0x7ce218
// 00680aaa  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00680ab1  894818               mov dword ptr [eax + 0x18], ecx
// 00680ab4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
