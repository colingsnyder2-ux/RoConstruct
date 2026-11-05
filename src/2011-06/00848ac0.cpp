// from server: 100% by auto
// roc 2011-06 00848ac0  unit: VCPtrList::?$CTypedPtrList  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00848ac0
//
// 00848ac0  8bc1                 mov eax, ecx
// 00848ac2  33c9                 xor ecx, ecx
// 00848ac4  894804               mov dword ptr [eax + 4], ecx
// 00848ac7  89480c               mov dword ptr [eax + 0xc], ecx
// 00848aca  894810               mov dword ptr [eax + 0x10], ecx
// 00848acd  894814               mov dword ptr [eax + 0x14], ecx
// 00848ad0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00848ad4  c700c064ac00         mov dword ptr [eax], 0xac64c0
// 00848ada  c7400811000000       mov dword ptr [eax + 8], 0x11
// 00848ae1  894818               mov dword ptr [eax + 0x18], ecx
// 00848ae4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??0?$CMap@PAUHICON__@@PAU1@HH@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
