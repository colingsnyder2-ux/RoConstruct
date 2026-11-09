// from server: 100% by auto
// roc 2008-06 0076a670  unit: CXTPDockingPaneContext  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0076a670
//
// 0076a670  8bc1                 mov eax, ecx
// 0076a672  33c9                 xor ecx, ecx
// 0076a674  89480c               mov dword ptr [eax + 0xc], ecx
// 0076a677  894810               mov dword ptr [eax + 0x10], ecx
// 0076a67a  894808               mov dword ptr [eax + 8], ecx
// 0076a67d  894804               mov dword ptr [eax + 4], ecx
// 0076a680  894814               mov dword ptr [eax + 0x14], ecx
// 0076a683  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0076a687  c700fc718600         mov dword ptr [eax], 0x8671fc
// 0076a68d  894818               mov dword ptr [eax + 0x18], ecx
// 0076a690  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
