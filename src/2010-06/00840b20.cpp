// from server: 100% by auto
// roc 2010-06 00840b20  unit: CXTPHookManagerHookAble  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00840b20
//
// 00840b20  8bc1                 mov eax, ecx
// 00840b22  33c9                 xor ecx, ecx
// 00840b24  89480c               mov dword ptr [eax + 0xc], ecx
// 00840b27  894810               mov dword ptr [eax + 0x10], ecx
// 00840b2a  894808               mov dword ptr [eax + 8], ecx
// 00840b2d  894804               mov dword ptr [eax + 4], ecx
// 00840b30  894814               mov dword ptr [eax + 0x14], ecx
// 00840b33  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00840b37  c700f073a600         mov dword ptr [eax], 0xa673f0
// 00840b3d  894818               mov dword ptr [eax + 0x18], ecx
// 00840b40  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
