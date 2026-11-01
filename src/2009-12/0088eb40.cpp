// from server: 100% by auto
// roc 2009-12 0088eb40  unit: CXTPShortcutManager::CKeyHelper  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088eb40
//
// 0088eb40  8bc1                 mov eax, ecx
// 0088eb42  33c9                 xor ecx, ecx
// 0088eb44  894804               mov dword ptr [eax + 4], ecx
// 0088eb47  89480c               mov dword ptr [eax + 0xc], ecx
// 0088eb4a  894810               mov dword ptr [eax + 0x10], ecx
// 0088eb4d  894814               mov dword ptr [eax + 0x14], ecx
// 0088eb50  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0088eb54  c7007c31a000         mov dword ptr [eax], 0xa0317c
// 0088eb5a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0088eb61  894818               mov dword ptr [eax + 0x18], ecx
// 0088eb64  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
