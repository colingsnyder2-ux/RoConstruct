// from server: 100% by auto
// roc 2009-06 00793280  unit: CXTPHookManagerHookAble  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00793280
//
// 00793280  8bc1                 mov eax, ecx
// 00793282  33c9                 xor ecx, ecx
// 00793284  894804               mov dword ptr [eax + 4], ecx
// 00793287  89480c               mov dword ptr [eax + 0xc], ecx
// 0079328a  894810               mov dword ptr [eax + 0x10], ecx
// 0079328d  894814               mov dword ptr [eax + 0x14], ecx
// 00793290  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00793294  c70020019000         mov dword ptr [eax], 0x900120
// 0079329a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007932a1  894818               mov dword ptr [eax + 0x18], ecx
// 007932a4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
