// from server: 100% by auto
// roc 2007-08 006a2cb0  unit: CXTPHookManagerHookAble  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a2cb0
//
// 006a2cb0  8bc1                 mov eax, ecx
// 006a2cb2  33c9                 xor ecx, ecx
// 006a2cb4  894804               mov dword ptr [eax + 4], ecx
// 006a2cb7  89480c               mov dword ptr [eax + 0xc], ecx
// 006a2cba  894810               mov dword ptr [eax + 0x10], ecx
// 006a2cbd  894814               mov dword ptr [eax + 0x14], ecx
// 006a2cc0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006a2cc4  c700f0347d00         mov dword ptr [eax], 0x7d34f0
// 006a2cca  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006a2cd1  894818               mov dword ptr [eax + 0x18], ecx
// 006a2cd4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
