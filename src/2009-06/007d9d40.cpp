// from server: 100% by auto
// roc 2009-06 007d9d40  unit: CXTPDockingPaneSplitterContainer  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d9d40
//
// 007d9d40  8bc1                 mov eax, ecx
// 007d9d42  33c9                 xor ecx, ecx
// 007d9d44  89480c               mov dword ptr [eax + 0xc], ecx
// 007d9d47  894810               mov dword ptr [eax + 0x10], ecx
// 007d9d4a  894808               mov dword ptr [eax + 8], ecx
// 007d9d4d  894804               mov dword ptr [eax + 4], ecx
// 007d9d50  894814               mov dword ptr [eax + 0x14], ecx
// 007d9d53  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007d9d57  c70068759000         mov dword ptr [eax], 0x907568
// 007d9d5d  894818               mov dword ptr [eax + 0x18], ecx
// 007d9d60  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
