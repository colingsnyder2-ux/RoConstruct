// from server: 100% by auto
// roc 2008-06 006fbb10  unit: CXTPPropertyGrid  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fbb10
//
// 006fbb10  8bc1                 mov eax, ecx
// 006fbb12  33c9                 xor ecx, ecx
// 006fbb14  894804               mov dword ptr [eax + 4], ecx
// 006fbb17  89480c               mov dword ptr [eax + 0xc], ecx
// 006fbb1a  894810               mov dword ptr [eax + 0x10], ecx
// 006fbb1d  894814               mov dword ptr [eax + 0x14], ecx
// 006fbb20  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006fbb24  c7008c378100         mov dword ptr [eax], 0x81378c
// 006fbb2a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006fbb31  894818               mov dword ptr [eax + 0x18], ecx
// 006fbb34  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
