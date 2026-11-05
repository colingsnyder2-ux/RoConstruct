// from server: 100% by auto
// roc 2008-06 0071e350  unit: CXTPShortcutManager::CKeyHelper  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0071e350
//
// 0071e350  8bc1                 mov eax, ecx
// 0071e352  33c9                 xor ecx, ecx
// 0071e354  894804               mov dword ptr [eax + 4], ecx
// 0071e357  89480c               mov dword ptr [eax + 0xc], ecx
// 0071e35a  894810               mov dword ptr [eax + 0x10], ecx
// 0071e35d  894814               mov dword ptr [eax + 0x14], ecx
// 0071e360  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071e364  c700e0f48500         mov dword ptr [eax], 0x85f4e0
// 0071e36a  c7400811000000       mov dword ptr [eax + 8], 0x11
// 0071e371  894818               mov dword ptr [eax + 0x18], ecx
// 0071e374  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
