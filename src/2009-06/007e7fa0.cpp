// from server: 100% by auto
// roc 2009-06 007e7fa0  unit: CXTPImageEditorDlg  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e7fa0
//
// 007e7fa0  8bc1                 mov eax, ecx
// 007e7fa2  33c9                 xor ecx, ecx
// 007e7fa4  89480c               mov dword ptr [eax + 0xc], ecx
// 007e7fa7  894810               mov dword ptr [eax + 0x10], ecx
// 007e7faa  894808               mov dword ptr [eax + 8], ecx
// 007e7fad  894804               mov dword ptr [eax + 4], ecx
// 007e7fb0  894814               mov dword ptr [eax + 0x14], ecx
// 007e7fb3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007e7fb7  c7002c8a9000         mov dword ptr [eax], 0x908a2c
// 007e7fbd  894818               mov dword ptr [eax + 0x18], ecx
// 007e7fc0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
