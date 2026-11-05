// from server: 100% by auto
// roc 2010-06 007ed820  unit: CXTPDockingPaneManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ed820
//
// 007ed820  8bc1                 mov eax, ecx
// 007ed822  33c9                 xor ecx, ecx
// 007ed824  89480c               mov dword ptr [eax + 0xc], ecx
// 007ed827  894810               mov dword ptr [eax + 0x10], ecx
// 007ed82a  894808               mov dword ptr [eax + 8], ecx
// 007ed82d  894804               mov dword ptr [eax + 4], ecx
// 007ed830  894814               mov dword ptr [eax + 0x14], ecx
// 007ed833  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007ed837  c70010c3a500         mov dword ptr [eax], 0xa5c310
// 007ed83d  894818               mov dword ptr [eax + 0x18], ecx
// 007ed840  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
