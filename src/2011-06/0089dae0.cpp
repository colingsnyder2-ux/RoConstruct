// from server: 100% by auto
// roc 2011-06 0089dae0  unit: CXTPHookManagerHookAble  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089dae0
//
// 0089dae0  8bc1                 mov eax, ecx
// 0089dae2  33c9                 xor ecx, ecx
// 0089dae4  89480c               mov dword ptr [eax + 0xc], ecx
// 0089dae7  894810               mov dword ptr [eax + 0x10], ecx
// 0089daea  894808               mov dword ptr [eax + 8], ecx
// 0089daed  894804               mov dword ptr [eax + 4], ecx
// 0089daf0  894814               mov dword ptr [eax + 0x14], ecx
// 0089daf3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0089daf7  c700101ead00         mov dword ptr [eax], 0xad1e10
// 0089dafd  894818               mov dword ptr [eax + 0x18], ecx
// 0089db00  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
