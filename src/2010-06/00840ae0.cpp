// from server: 100% by auto
// roc 2010-06 00840ae0  unit: CXTPHookManagerHookAble  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00840ae0
//
// 00840ae0  8bc1                 mov eax, ecx
// 00840ae2  33c9                 xor ecx, ecx
// 00840ae4  894804               mov dword ptr [eax + 4], ecx
// 00840ae7  89480c               mov dword ptr [eax + 0xc], ecx
// 00840aea  894810               mov dword ptr [eax + 0x10], ecx
// 00840aed  894814               mov dword ptr [eax + 0x14], ecx
// 00840af0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00840af4  c700d873a600         mov dword ptr [eax], 0xa673d8
// 00840afa  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00840b01  894818               mov dword ptr [eax + 0x18], ecx
// 00840b04  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
