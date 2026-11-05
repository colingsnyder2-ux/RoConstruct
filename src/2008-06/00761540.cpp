// from server: 100% by auto
// roc 2008-06 00761540  unit: CXTPDockingPaneSplitterContainer  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00761540
//
// 00761540  8bc1                 mov eax, ecx
// 00761542  33c9                 xor ecx, ecx
// 00761544  89480c               mov dword ptr [eax + 0xc], ecx
// 00761547  894810               mov dword ptr [eax + 0x10], ecx
// 0076154a  894808               mov dword ptr [eax + 8], ecx
// 0076154d  894804               mov dword ptr [eax + 4], ecx
// 00761550  894814               mov dword ptr [eax + 0x14], ecx
// 00761553  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00761557  c70030658600         mov dword ptr [eax], 0x866530
// 0076155d  894818               mov dword ptr [eax + 0x18], ecx
// 00761560  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
