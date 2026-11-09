// from server: 100% by auto
// roc 2009-12 00870630  unit: CXTPHookManagerHookAble  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00870630
//
// 00870630  8bc1                 mov eax, ecx
// 00870632  33c9                 xor ecx, ecx
// 00870634  894804               mov dword ptr [eax + 4], ecx
// 00870637  89480c               mov dword ptr [eax + 0xc], ecx
// 0087063a  894810               mov dword ptr [eax + 0x10], ecx
// 0087063d  894814               mov dword ptr [eax + 0x14], ecx
// 00870640  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00870644  c700500da000         mov dword ptr [eax], 0xa00d50
// 0087064a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00870651  894818               mov dword ptr [eax + 0x18], ecx
// 00870654  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
