// from server: 100% by auto
// roc 2008-06 0071c490  unit: CXTPHookManagerHookAble  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071c490
//
// 0071c490  8bc1                 mov eax, ecx
// 0071c492  33c9                 xor ecx, ecx
// 0071c494  894804               mov dword ptr [eax + 4], ecx
// 0071c497  89480c               mov dword ptr [eax + 0xc], ecx
// 0071c49a  894810               mov dword ptr [eax + 0x10], ecx
// 0071c49d  894814               mov dword ptr [eax + 0x14], ecx
// 0071c4a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071c4a4  c700c0f38500         mov dword ptr [eax], 0x85f3c0
// 0071c4aa  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0071c4b1  894818               mov dword ptr [eax + 0x18], ecx
// 0071c4b4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
