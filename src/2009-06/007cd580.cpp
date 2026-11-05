// from server: 100% by auto
// roc 2009-06 007cd580  unit: CXTPDockingPaneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cd580
//
// 007cd580  8bc1                 mov eax, ecx
// 007cd582  33c9                 xor ecx, ecx
// 007cd584  894804               mov dword ptr [eax + 4], ecx
// 007cd587  89480c               mov dword ptr [eax + 0xc], ecx
// 007cd58a  894810               mov dword ptr [eax + 0x10], ecx
// 007cd58d  894814               mov dword ptr [eax + 0x14], ecx
// 007cd590  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007cd594  c700945e9000         mov dword ptr [eax], 0x905e94
// 007cd59a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007cd5a1  894818               mov dword ptr [eax + 0x18], ecx
// 007cd5a4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
