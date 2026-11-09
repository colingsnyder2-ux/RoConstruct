// from server: 100% by auto
// roc 2011-06 0089fef0  unit: CXTPShortcutManager::CKeyHelper  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0089fef0
//
// 0089fef0  8bc1                 mov eax, ecx
// 0089fef2  33c9                 xor ecx, ecx
// 0089fef4  894804               mov dword ptr [eax + 4], ecx
// 0089fef7  89480c               mov dword ptr [eax + 0xc], ecx
// 0089fefa  894810               mov dword ptr [eax + 0x10], ecx
// 0089fefd  894814               mov dword ptr [eax + 0x14], ecx
// 0089ff00  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0089ff04  c700981ead00         mov dword ptr [eax], 0xad1e98
// 0089ff0a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0089ff11  894818               mov dword ptr [eax + 0x18], ecx
// 0089ff14  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
