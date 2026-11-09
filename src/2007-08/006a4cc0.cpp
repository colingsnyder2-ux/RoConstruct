// from server: 100% by auto
// roc 2007-08 006a4cc0  unit: CXTPShortcutManager::CKeyHelper  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a4cc0
//
// 006a4cc0  8bc1                 mov eax, ecx
// 006a4cc2  33c9                 xor ecx, ecx
// 006a4cc4  894804               mov dword ptr [eax + 4], ecx
// 006a4cc7  89480c               mov dword ptr [eax + 0xc], ecx
// 006a4cca  894810               mov dword ptr [eax + 0x10], ecx
// 006a4ccd  894814               mov dword ptr [eax + 0x14], ecx
// 006a4cd0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006a4cd4  c70010367d00         mov dword ptr [eax], 0x7d3610
// 006a4cda  c7400811000000       mov dword ptr [eax + 8], 0x11
// 006a4ce1  894818               mov dword ptr [eax + 0x18], ecx
// 006a4ce4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
