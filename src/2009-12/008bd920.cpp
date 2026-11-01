// from server: 100% by auto
// roc 2009-12 008bd920  unit: CXTPDockingPaneContext  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008bd920
//
// 008bd920  8bc1                 mov eax, ecx
// 008bd922  33c9                 xor ecx, ecx
// 008bd924  894804               mov dword ptr [eax + 4], ecx
// 008bd927  89480c               mov dword ptr [eax + 0xc], ecx
// 008bd92a  894810               mov dword ptr [eax + 0x10], ecx
// 008bd92d  894814               mov dword ptr [eax + 0x14], ecx
// 008bd930  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008bd934  c700bc86a000         mov dword ptr [eax], 0xa086bc
// 008bd93a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 008bd941  894818               mov dword ptr [eax + 0x18], ecx
// 008bd944  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
