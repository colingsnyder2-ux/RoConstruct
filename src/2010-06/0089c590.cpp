// from server: 100% by auto
// roc 2010-06 0089c590  unit: CXTPTabPaintManager::CColorSetDefault  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089c590
//
// 0089c590  8b01                 mov eax, dword ptr [ecx]
// 0089c592  8b542418             mov edx, dword ptr [esp + 0x18]
// 0089c596  8b4024               mov eax, dword ptr [eax + 0x24]
// 0089c599  56                   push esi
// 0089c59a  52                   push edx
// 0089c59b  ffd0                 call eax
// 0089c59d  8bf0                 mov esi, eax
// 0089c59f  56                   push esi
// 0089c5a0  8d4c2410             lea ecx, [esp + 0x10]
// 0089c5a4  51                   push ecx
// 0089c5a5  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0089c5a9  e890c1f0ff           call 0x7a873e
// 0089c5ae  8bc6                 mov eax, esi
// 0089c5b0  5e                   pop esi
// 0089c5b1  c21800               ret 0x18
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?FillPropertyButton@CColorSet@CXTPTabPaintManager@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
