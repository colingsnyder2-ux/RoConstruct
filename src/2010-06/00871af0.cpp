// from server: 100% by auto
// roc 2010-06 00871af0  unit: CXTPDockingPaneContext  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00871af0
//
// 00871af0  8bc1                 mov eax, ecx
// 00871af2  33c9                 xor ecx, ecx
// 00871af4  894804               mov dword ptr [eax + 4], ecx
// 00871af7  89480c               mov dword ptr [eax + 0xc], ecx
// 00871afa  894810               mov dword ptr [eax + 0x10], ecx
// 00871afd  894814               mov dword ptr [eax + 0x14], ecx
// 00871b00  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00871b04  c700a4c9a600         mov dword ptr [eax], 0xa6c9a4
// 00871b0a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00871b11  894818               mov dword ptr [eax + 0x18], ecx
// 00871b14  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
