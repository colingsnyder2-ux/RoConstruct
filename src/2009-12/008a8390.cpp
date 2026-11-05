// from server: 100% by auto
// roc 2009-12 008a8390  unit: CXTPDockingPaneBase  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a8390
//
// 008a8390  8bc1                 mov eax, ecx
// 008a8392  33c9                 xor ecx, ecx
// 008a8394  894804               mov dword ptr [eax + 4], ecx
// 008a8397  89480c               mov dword ptr [eax + 0xc], ecx
// 008a839a  894810               mov dword ptr [eax + 0x10], ecx
// 008a839d  894814               mov dword ptr [eax + 0x14], ecx
// 008a83a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008a83a4  c7001463a000         mov dword ptr [eax], 0xa06314
// 008a83aa  c7400811000000       mov dword ptr [eax + 8], 0x11
// 008a83b1  894818               mov dword ptr [eax + 0x18], ecx
// 008a83b4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
