// from server: 100% by auto
// roc 2010-06 0085c490  unit: CXTPDockingPaneBase  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0085c490
//
// 0085c490  8bc1                 mov eax, ecx
// 0085c492  33c9                 xor ecx, ecx
// 0085c494  89480c               mov dword ptr [eax + 0xc], ecx
// 0085c497  894810               mov dword ptr [eax + 0x10], ecx
// 0085c49a  894808               mov dword ptr [eax + 8], ecx
// 0085c49d  894804               mov dword ptr [eax + 4], ecx
// 0085c4a0  894814               mov dword ptr [eax + 0x14], ecx
// 0085c4a3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0085c4a7  c700e4a5a600         mov dword ptr [eax], 0xa6a5e4
// 0085c4ad  894818               mov dword ptr [eax + 0x18], ecx
// 0085c4b0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
