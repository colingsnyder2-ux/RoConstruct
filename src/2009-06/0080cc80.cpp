// from server: 100% by auto
// roc 2009-06 0080cc80  unit: CXTPTabPaintManager::CColorSetDefault  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080cc80
//
// 0080cc80  8b01                 mov eax, dword ptr [ecx]
// 0080cc82  8b542418             mov edx, dword ptr [esp + 0x18]
// 0080cc86  8b4024               mov eax, dword ptr [eax + 0x24]
// 0080cc89  56                   push esi
// 0080cc8a  52                   push edx
// 0080cc8b  ffd0                 call eax
// 0080cc8d  8bf0                 mov esi, eax
// 0080cc8f  56                   push esi
// 0080cc90  8d4c2410             lea ecx, [esp + 0x10]
// 0080cc94  51                   push ecx
// 0080cc95  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0080cc99  e832cbf0ff           call 0x7197d0
// 0080cc9e  8bc6                 mov eax, esi
// 0080cca0  5e                   pop esi
// 0080cca1  c21800               ret 0x18
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?FillPropertyButton@CXTPTabPaintManagerColorSet@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
