// from server: 100% by auto
// roc 2009-06 007d1c40  unit: CXTPDockingPaneWindowSelect  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d1c40
//
// 007d1c40  8bc1                 mov eax, ecx
// 007d1c42  33c9                 xor ecx, ecx
// 007d1c44  894804               mov dword ptr [eax + 4], ecx
// 007d1c47  89480c               mov dword ptr [eax + 0xc], ecx
// 007d1c4a  894810               mov dword ptr [eax + 0x10], ecx
// 007d1c4d  894814               mov dword ptr [eax + 0x14], ecx
// 007d1c50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007d1c54  c700ec669000         mov dword ptr [eax], 0x9066ec
// 007d1c5a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007d1c61  894818               mov dword ptr [eax + 0x18], ecx
// 007d1c64  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
