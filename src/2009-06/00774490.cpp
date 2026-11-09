// from server: 100% by auto
// roc 2009-06 00774490  unit: CXTPPropertyGrid  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00774490
//
// 00774490  8bc1                 mov eax, ecx
// 00774492  33c9                 xor ecx, ecx
// 00774494  894804               mov dword ptr [eax + 4], ecx
// 00774497  89480c               mov dword ptr [eax + 0xc], ecx
// 0077449a  894810               mov dword ptr [eax + 0x10], ecx
// 0077449d  894814               mov dword ptr [eax + 0x14], ecx
// 007744a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007744a4  c7004c3d8b00         mov dword ptr [eax], 0x8b3d4c
// 007744aa  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007744b1  894818               mov dword ptr [eax + 0x18], ecx
// 007744b4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
