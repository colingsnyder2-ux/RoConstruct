// from server: 100% by auto
// roc 2009-06 007b4b20  unit: CXTPShortcutManager::CKeyHelper  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b4b20
//
// 007b4b20  8bc1                 mov eax, ecx
// 007b4b22  33c9                 xor ecx, ecx
// 007b4b24  894804               mov dword ptr [eax + 4], ecx
// 007b4b27  89480c               mov dword ptr [eax + 0xc], ecx
// 007b4b2a  894810               mov dword ptr [eax + 0x10], ecx
// 007b4b2d  894814               mov dword ptr [eax + 0x14], ecx
// 007b4b30  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007b4b34  c700bc2f9000         mov dword ptr [eax], 0x902fbc
// 007b4b3a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 007b4b41  894818               mov dword ptr [eax + 0x18], ecx
// 007b4b44  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
