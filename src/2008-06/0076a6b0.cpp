// from server: 100% by auto
// roc 2008-06 0076a6b0  unit: CXTPDockingPaneContext  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0076a6b0
//
// 0076a6b0  8bc1                 mov eax, ecx
// 0076a6b2  33c9                 xor ecx, ecx
// 0076a6b4  894804               mov dword ptr [eax + 4], ecx
// 0076a6b7  89480c               mov dword ptr [eax + 0xc], ecx
// 0076a6ba  894810               mov dword ptr [eax + 0x10], ecx
// 0076a6bd  894814               mov dword ptr [eax + 0x14], ecx
// 0076a6c0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0076a6c4  c70014728600         mov dword ptr [eax], 0x867214
// 0076a6ca  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0076a6d1  894818               mov dword ptr [eax + 0x18], ecx
// 0076a6d4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
