// from server: 100% by auto
// roc 2008-06 0071c4d0  unit: CXTPHookManagerHookAble  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071c4d0
//
// 0071c4d0  8bc1                 mov eax, ecx
// 0071c4d2  33c9                 xor ecx, ecx
// 0071c4d4  89480c               mov dword ptr [eax + 0xc], ecx
// 0071c4d7  894810               mov dword ptr [eax + 0x10], ecx
// 0071c4da  894808               mov dword ptr [eax + 8], ecx
// 0071c4dd  894804               mov dword ptr [eax + 4], ecx
// 0071c4e0  894814               mov dword ptr [eax + 0x14], ecx
// 0071c4e3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071c4e7  c700d8f38500         mov dword ptr [eax], 0x85f3d8
// 0071c4ed  894818               mov dword ptr [eax + 0x18], ecx
// 0071c4f0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
