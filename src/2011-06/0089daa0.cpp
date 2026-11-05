// from server: 100% by auto
// roc 2011-06 0089daa0  unit: CXTPHookManagerHookAble  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089daa0
//
// 0089daa0  8bc1                 mov eax, ecx
// 0089daa2  33c9                 xor ecx, ecx
// 0089daa4  894804               mov dword ptr [eax + 4], ecx
// 0089daa7  89480c               mov dword ptr [eax + 0xc], ecx
// 0089daaa  894810               mov dword ptr [eax + 0x10], ecx
// 0089daad  894814               mov dword ptr [eax + 0x14], ecx
// 0089dab0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0089dab4  c700f81dad00         mov dword ptr [eax], 0xad1df8
// 0089daba  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0089dac1  894818               mov dword ptr [eax + 0x18], ecx
// 0089dac4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
