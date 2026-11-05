// from server: 100% by auto
// roc 2008-06 0076f870  unit: CXTPImageEditorDlg  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0076f870
//
// 0076f870  8bc1                 mov eax, ecx
// 0076f872  33c9                 xor ecx, ecx
// 0076f874  89480c               mov dword ptr [eax + 0xc], ecx
// 0076f877  894810               mov dword ptr [eax + 0x10], ecx
// 0076f87a  894808               mov dword ptr [eax + 8], ecx
// 0076f87d  894804               mov dword ptr [eax + 4], ecx
// 0076f880  894814               mov dword ptr [eax + 0x14], ecx
// 0076f883  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0076f887  c700fc798600         mov dword ptr [eax], 0x8679fc
// 0076f88d  894818               mov dword ptr [eax + 0x18], ecx
// 0076f890  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
