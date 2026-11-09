// from server: 100% by auto
// roc 2008-06 00754ee0  unit: CXTPDockingPaneBase  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00754ee0
//
// 00754ee0  8bc1                 mov eax, ecx
// 00754ee2  33c9                 xor ecx, ecx
// 00754ee4  89480c               mov dword ptr [eax + 0xc], ecx
// 00754ee7  894810               mov dword ptr [eax + 0x10], ecx
// 00754eea  894808               mov dword ptr [eax + 8], ecx
// 00754eed  894804               mov dword ptr [eax + 4], ecx
// 00754ef0  894814               mov dword ptr [eax + 0x14], ecx
// 00754ef3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00754ef7  c700444e8600         mov dword ptr [eax], 0x864e44
// 00754efd  894818               mov dword ptr [eax + 0x18], ecx
// 00754f00  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
