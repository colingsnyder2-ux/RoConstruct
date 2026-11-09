// from server: 100% by auto
// roc 2009-06 00808a60  unit: CXTShadowWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00808a60
//
// 00808a60  8bc1                 mov eax, ecx
// 00808a62  33c9                 xor ecx, ecx
// 00808a64  89480c               mov dword ptr [eax + 0xc], ecx
// 00808a67  894810               mov dword ptr [eax + 0x10], ecx
// 00808a6a  894808               mov dword ptr [eax + 8], ecx
// 00808a6d  894804               mov dword ptr [eax + 4], ecx
// 00808a70  894814               mov dword ptr [eax + 0x14], ecx
// 00808a73  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00808a77  c700f4bd9000         mov dword ptr [eax], 0x90bdf4
// 00808a7d  894818               mov dword ptr [eax + 0x18], ecx
// 00808a80  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
