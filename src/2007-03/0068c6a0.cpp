// from server: 100% by auto
// roc 2007-03 0068c6a0  unit: seg_00680000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068c6a0
//
// 0068c6a0  8bc1                 mov eax, ecx
// 0068c6a2  33c9                 xor ecx, ecx
// 0068c6a4  894804               mov dword ptr [eax + 4], ecx
// 0068c6a7  89480c               mov dword ptr [eax + 0xc], ecx
// 0068c6aa  894810               mov dword ptr [eax + 0x10], ecx
// 0068c6ad  894814               mov dword ptr [eax + 0x14], ecx
// 0068c6b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068c6b4  c700f8ff7c00         mov dword ptr [eax], 0x7cfff8
// 0068c6ba  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0068c6c1  894818               mov dword ptr [eax + 0x18], ecx
// 0068c6c4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
