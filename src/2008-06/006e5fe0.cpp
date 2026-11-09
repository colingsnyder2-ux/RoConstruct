// from server: 100% by auto
// roc 2008-06 006e5fe0  unit: CXTPDockingPaneManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006e5fe0
//
// 006e5fe0  8bc1                 mov eax, ecx
// 006e5fe2  33c9                 xor ecx, ecx
// 006e5fe4  89480c               mov dword ptr [eax + 0xc], ecx
// 006e5fe7  894810               mov dword ptr [eax + 0x10], ecx
// 006e5fea  894808               mov dword ptr [eax + 8], ecx
// 006e5fed  894804               mov dword ptr [eax + 4], ecx
// 006e5ff0  894814               mov dword ptr [eax + 0x14], ecx
// 006e5ff3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006e5ff7  c700506b8500         mov dword ptr [eax], 0x856b50
// 006e5ffd  894818               mov dword ptr [eax + 0x18], ecx
// 006e6000  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
