// from server: 100% by auto
// roc 2008-06 007903e0  unit: CXTShadowWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007903e0
//
// 007903e0  8bc1                 mov eax, ecx
// 007903e2  33c9                 xor ecx, ecx
// 007903e4  89480c               mov dword ptr [eax + 0xc], ecx
// 007903e7  894810               mov dword ptr [eax + 0x10], ecx
// 007903ea  894808               mov dword ptr [eax + 8], ecx
// 007903ed  894804               mov dword ptr [eax + 4], ecx
// 007903f0  894814               mov dword ptr [eax + 0x14], ecx
// 007903f3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007903f7  c700ccad8600         mov dword ptr [eax], 0x86adcc
// 007903fd  894818               mov dword ptr [eax + 0x18], ecx
// 00790400  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
