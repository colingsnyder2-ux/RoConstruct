// from server: 100% by auto
// roc 2009-06 007cd5c0  unit: CXTPDockingPaneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cd5c0
//
// 007cd5c0  8bc1                 mov eax, ecx
// 007cd5c2  33c9                 xor ecx, ecx
// 007cd5c4  894804               mov dword ptr [eax + 4], ecx
// 007cd5c7  89480c               mov dword ptr [eax + 0xc], ecx
// 007cd5ca  894810               mov dword ptr [eax + 0x10], ecx
// 007cd5cd  894814               mov dword ptr [eax + 0x14], ecx
// 007cd5d0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007cd5d4  c700ac5e9000         mov dword ptr [eax], 0x905eac
// 007cd5da  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007cd5e1  894818               mov dword ptr [eax + 0x18], ecx
// 007cd5e4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
