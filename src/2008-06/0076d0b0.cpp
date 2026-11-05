// from server: 100% by auto
// roc 2008-06 0076d0b0  unit: CXTPShadowsManager::CShadowWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0076d0b0
//
// 0076d0b0  8bc1                 mov eax, ecx
// 0076d0b2  33c9                 xor ecx, ecx
// 0076d0b4  89480c               mov dword ptr [eax + 0xc], ecx
// 0076d0b7  894810               mov dword ptr [eax + 0x10], ecx
// 0076d0ba  894808               mov dword ptr [eax + 8], ecx
// 0076d0bd  894804               mov dword ptr [eax + 4], ecx
// 0076d0c0  894814               mov dword ptr [eax + 0x14], ecx
// 0076d0c3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0076d0c7  c70064748600         mov dword ptr [eax], 0x867464
// 0076d0cd  894818               mov dword ptr [eax + 0x18], ecx
// 0076d0d0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
