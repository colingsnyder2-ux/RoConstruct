// from server: 100% by auto
// roc 2010-06 00842d30  unit: CXTPShortcutManager::CKeyHelper  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00842d30
//
// 00842d30  8bc1                 mov eax, ecx
// 00842d32  33c9                 xor ecx, ecx
// 00842d34  894804               mov dword ptr [eax + 4], ecx
// 00842d37  89480c               mov dword ptr [eax + 0xc], ecx
// 00842d3a  894810               mov dword ptr [eax + 0x10], ecx
// 00842d3d  894814               mov dword ptr [eax + 0x14], ecx
// 00842d40  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00842d44  c7007874a600         mov dword ptr [eax], 0xa67478
// 00842d4a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00842d51  894818               mov dword ptr [eax + 0x18], ecx
// 00842d54  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
