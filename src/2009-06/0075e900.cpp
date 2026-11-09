// from server: 100% by auto
// roc 2009-06 0075e900  unit: CXTPDockingPaneManager  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075e900
//
// 0075e900  8bc1                 mov eax, ecx
// 0075e902  33c9                 xor ecx, ecx
// 0075e904  89480c               mov dword ptr [eax + 0xc], ecx
// 0075e907  894810               mov dword ptr [eax + 0x10], ecx
// 0075e90a  894808               mov dword ptr [eax + 8], ecx
// 0075e90d  894804               mov dword ptr [eax + 4], ecx
// 0075e910  894814               mov dword ptr [eax + 0x14], ecx
// 0075e913  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0075e917  c700a87b8f00         mov dword ptr [eax], 0x8f7ba8
// 0075e91d  894818               mov dword ptr [eax + 0x18], ecx
// 0075e920  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
