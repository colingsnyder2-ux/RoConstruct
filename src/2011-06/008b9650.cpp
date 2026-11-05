// from server: 100% by auto
// roc 2011-06 008b9650  unit: CXTPDockingPaneBase  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008b9650
//
// 008b9650  8bc1                 mov eax, ecx
// 008b9652  33c9                 xor ecx, ecx
// 008b9654  89480c               mov dword ptr [eax + 0xc], ecx
// 008b9657  894810               mov dword ptr [eax + 0x10], ecx
// 008b965a  894808               mov dword ptr [eax + 8], ecx
// 008b965d  894804               mov dword ptr [eax + 4], ecx
// 008b9660  894814               mov dword ptr [eax + 0x14], ecx
// 008b9663  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008b9667  c700f84fad00         mov dword ptr [eax], 0xad4ff8
// 008b966d  894818               mov dword ptr [eax + 0x18], ecx
// 008b9670  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
