// from server: 100% by auto
// roc 2011-06 0086a900  unit: CXTPPropertyGrid  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086a900
//
// 0086a900  8bc1                 mov eax, ecx
// 0086a902  33c9                 xor ecx, ecx
// 0086a904  894804               mov dword ptr [eax + 4], ecx
// 0086a907  89480c               mov dword ptr [eax + 0xc], ecx
// 0086a90a  894810               mov dword ptr [eax + 0x10], ecx
// 0086a90d  894814               mov dword ptr [eax + 0x14], ecx
// 0086a910  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0086a914  c700c092a600         mov dword ptr [eax], 0xa692c0
// 0086a91a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0086a921  894818               mov dword ptr [eax + 0x18], ecx
// 0086a924  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
