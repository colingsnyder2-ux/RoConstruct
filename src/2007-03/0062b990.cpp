// from server: 100% by auto
// roc 2007-03 0062b990  unit: seg_00620000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062b990
//
// 0062b990  8bc1                 mov eax, ecx
// 0062b992  33c9                 xor ecx, ecx
// 0062b994  894804               mov dword ptr [eax + 4], ecx
// 0062b997  89480c               mov dword ptr [eax + 0xc], ecx
// 0062b99a  894810               mov dword ptr [eax + 0x10], ecx
// 0062b99d  894814               mov dword ptr [eax + 0x14], ecx
// 0062b9a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0062b9a4  c700f0357c00         mov dword ptr [eax], 0x7c35f0
// 0062b9aa  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0062b9b1  894818               mov dword ptr [eax + 0x18], ecx
// 0062b9b4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
