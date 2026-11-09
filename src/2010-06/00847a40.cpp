// from server: 100% by auto
// roc 2010-06 00847a40  unit: CXTPMenuBar  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00847a40
//
// 00847a40  8bc1                 mov eax, ecx
// 00847a42  33c9                 xor ecx, ecx
// 00847a44  894804               mov dword ptr [eax + 4], ecx
// 00847a47  89480c               mov dword ptr [eax + 0xc], ecx
// 00847a4a  894810               mov dword ptr [eax + 0x10], ecx
// 00847a4d  894814               mov dword ptr [eax + 0x14], ecx
// 00847a50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00847a54  c7009084a600         mov dword ptr [eax], 0xa68490
// 00847a5a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00847a61  894818               mov dword ptr [eax + 0x18], ecx
// 00847a64  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
