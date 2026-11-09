// from server: 100% by auto
// roc 2011-06 0084f070  unit: CXTPDockingPaneManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0084f070
//
// 0084f070  8bc1                 mov eax, ecx
// 0084f072  33c9                 xor ecx, ecx
// 0084f074  89480c               mov dword ptr [eax + 0xc], ecx
// 0084f077  894810               mov dword ptr [eax + 0x10], ecx
// 0084f07a  894808               mov dword ptr [eax + 8], ecx
// 0084f07d  894804               mov dword ptr [eax + 4], ecx
// 0084f080  894814               mov dword ptr [eax + 0x14], ecx
// 0084f083  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0084f087  c700587fac00         mov dword ptr [eax], 0xac7f58
// 0084f08d  894818               mov dword ptr [eax + 0x18], ecx
// 0084f090  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
