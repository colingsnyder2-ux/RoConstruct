// from server: 100% by auto
// roc 2007-03 00627a30  unit: seg_00620000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00627a30
//
// 00627a30  8bc1                 mov eax, ecx
// 00627a32  33c9                 xor ecx, ecx
// 00627a34  894804               mov dword ptr [eax + 4], ecx
// 00627a37  89480c               mov dword ptr [eax + 0xc], ecx
// 00627a3a  894810               mov dword ptr [eax + 0x10], ecx
// 00627a3d  894814               mov dword ptr [eax + 0x14], ecx
// 00627a40  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00627a44  c70038347c00         mov dword ptr [eax], 0x7c3438
// 00627a4a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00627a51  894818               mov dword ptr [eax + 0x18], ecx
// 00627a54  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
