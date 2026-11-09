// from server: 100% by auto
// roc 2010-06 00897810  unit: CXTShadowWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00897810
//
// 00897810  8bc1                 mov eax, ecx
// 00897812  33c9                 xor ecx, ecx
// 00897814  89480c               mov dword ptr [eax + 0xc], ecx
// 00897817  894810               mov dword ptr [eax + 0x10], ecx
// 0089781a  894808               mov dword ptr [eax + 8], ecx
// 0089781d  894804               mov dword ptr [eax + 4], ecx
// 00897820  894814               mov dword ptr [eax + 0x14], ecx
// 00897823  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00897827  c7005c05a700         mov dword ptr [eax], 0xa7055c
// 0089782d  894818               mov dword ptr [eax + 0x18], ecx
// 00897830  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
