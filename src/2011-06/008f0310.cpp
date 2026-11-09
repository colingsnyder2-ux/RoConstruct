// from server: 100% by auto
// roc 2011-06 008f0310  unit: CXTShadowWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f0310
//
// 008f0310  8bc1                 mov eax, ecx
// 008f0312  33c9                 xor ecx, ecx
// 008f0314  89480c               mov dword ptr [eax + 0xc], ecx
// 008f0317  894810               mov dword ptr [eax + 0x10], ecx
// 008f031a  894808               mov dword ptr [eax + 8], ecx
// 008f031d  894804               mov dword ptr [eax + 4], ecx
// 008f0320  894814               mov dword ptr [eax + 0x14], ecx
// 008f0323  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008f0327  c70084a0ad00         mov dword ptr [eax], 0xada084
// 008f032d  894818               mov dword ptr [eax + 0x18], ecx
// 008f0330  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
