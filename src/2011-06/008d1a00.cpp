// from server: 100% by auto
// roc 2011-06 008d1a00  unit: CXTPShadowsManager::CShadowWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d1a00
//
// 008d1a00  8bc1                 mov eax, ecx
// 008d1a02  33c9                 xor ecx, ecx
// 008d1a04  89480c               mov dword ptr [eax + 0xc], ecx
// 008d1a07  894810               mov dword ptr [eax + 0x10], ecx
// 008d1a0a  894808               mov dword ptr [eax + 8], ecx
// 008d1a0d  894804               mov dword ptr [eax + 4], ecx
// 008d1a10  894814               mov dword ptr [eax + 0x14], ecx
// 008d1a13  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008d1a17  c700fc75ad00         mov dword ptr [eax], 0xad75fc
// 008d1a1d  894818               mov dword ptr [eax + 0x18], ecx
// 008d1a20  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
