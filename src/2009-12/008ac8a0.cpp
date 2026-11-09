// from server: 100% by auto
// roc 2009-12 008ac8a0  unit: CXTPDockingPaneWindowSelect  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ac8a0
//
// 008ac8a0  8bc1                 mov eax, ecx
// 008ac8a2  33c9                 xor ecx, ecx
// 008ac8a4  894804               mov dword ptr [eax + 4], ecx
// 008ac8a7  89480c               mov dword ptr [eax + 0xc], ecx
// 008ac8aa  894810               mov dword ptr [eax + 0x10], ecx
// 008ac8ad  894814               mov dword ptr [eax + 0x14], ecx
// 008ac8b0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008ac8b4  c7005c6ba000         mov dword ptr [eax], 0xa06b5c
// 008ac8ba  c7400811000000       mov dword ptr [eax + 8], 0x11
// 008ac8c1  894818               mov dword ptr [eax + 0x18], ecx
// 008ac8c4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
