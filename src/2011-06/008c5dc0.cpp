// from server: 100% by auto
// roc 2011-06 008c5dc0  unit: CXTPDockingPaneSplitterContainer  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008c5dc0
//
// 008c5dc0  8bc1                 mov eax, ecx
// 008c5dc2  33c9                 xor ecx, ecx
// 008c5dc4  89480c               mov dword ptr [eax + 0xc], ecx
// 008c5dc7  894810               mov dword ptr [eax + 0x10], ecx
// 008c5dca  894808               mov dword ptr [eax + 8], ecx
// 008c5dcd  894804               mov dword ptr [eax + 4], ecx
// 008c5dd0  894814               mov dword ptr [eax + 0x14], ecx
// 008c5dd3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008c5dd7  c700d066ad00         mov dword ptr [eax], 0xad66d0
// 008c5ddd  894818               mov dword ptr [eax + 0x18], ecx
// 008c5de0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
