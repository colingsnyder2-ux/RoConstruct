// from server: 100% by auto
// roc 2010-06 00874500  unit: CXTPShadowsManager::CShadowWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00874500
//
// 00874500  8bc1                 mov eax, ecx
// 00874502  33c9                 xor ecx, ecx
// 00874504  89480c               mov dword ptr [eax + 0xc], ecx
// 00874507  894810               mov dword ptr [eax + 0x10], ecx
// 0087450a  894808               mov dword ptr [eax + 8], ecx
// 0087450d  894804               mov dword ptr [eax + 4], ecx
// 00874510  894814               mov dword ptr [eax + 0x14], ecx
// 00874513  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00874517  c700eccba600         mov dword ptr [eax], 0xa6cbec
// 0087451d  894818               mov dword ptr [eax + 0x18], ecx
// 00874520  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CList@UCMFCRestoredTabInfo@@U1@@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
