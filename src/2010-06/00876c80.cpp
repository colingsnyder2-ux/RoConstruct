// from server: 100% by auto
// roc 2010-06 00876c80  unit: CXTPImageEditorDlg  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00876c80
//
// 00876c80  8bc1                 mov eax, ecx
// 00876c82  33c9                 xor ecx, ecx
// 00876c84  89480c               mov dword ptr [eax + 0xc], ecx
// 00876c87  894810               mov dword ptr [eax + 0x10], ecx
// 00876c8a  894808               mov dword ptr [eax + 8], ecx
// 00876c8d  894804               mov dword ptr [eax + 4], ecx
// 00876c90  894814               mov dword ptr [eax + 0x14], ecx
// 00876c93  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00876c97  c70084d1a600         mov dword ptr [eax], 0xa6d184
// 00876c9d  894818               mov dword ptr [eax + 0x18], ecx
// 00876ca0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
