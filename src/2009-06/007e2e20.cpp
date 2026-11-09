// from server: 100% by auto
// roc 2009-06 007e2e20  unit: CXTPDockingPaneContext  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e2e20
//
// 007e2e20  8bc1                 mov eax, ecx
// 007e2e22  33c9                 xor ecx, ecx
// 007e2e24  89480c               mov dword ptr [eax + 0xc], ecx
// 007e2e27  894810               mov dword ptr [eax + 0x10], ecx
// 007e2e2a  894808               mov dword ptr [eax + 8], ecx
// 007e2e2d  894804               mov dword ptr [eax + 4], ecx
// 007e2e30  894814               mov dword ptr [eax + 0x14], ecx
// 007e2e33  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007e2e37  c70034829000         mov dword ptr [eax], 0x908234
// 007e2e3d  894818               mov dword ptr [eax + 0x18], ecx
// 007e2e40  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
