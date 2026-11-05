// from server: 100% by auto
// roc 2009-12 0084f1f0  unit: CXTPPropertyGrid  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084f1f0
//
// 0084f1f0  8bc1                 mov eax, ecx
// 0084f1f2  33c9                 xor ecx, ecx
// 0084f1f4  894804               mov dword ptr [eax + 4], ecx
// 0084f1f7  89480c               mov dword ptr [eax + 0xc], ecx
// 0084f1fa  894810               mov dword ptr [eax + 0x10], ecx
// 0084f1fd  894814               mov dword ptr [eax + 0x14], ecx
// 0084f200  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0084f204  c700906a9a00         mov dword ptr [eax], 0x9a6a90
// 0084f20a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0084f211  894818               mov dword ptr [eax + 0x18], ecx
// 0084f214  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
