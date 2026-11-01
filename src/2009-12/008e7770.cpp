// from server: 100% by auto
// roc 2009-12 008e7770  unit: CXTPTabPaintManager::CColorSetDefault  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e7770
//
// 008e7770  8b01                 mov eax, dword ptr [ecx]
// 008e7772  8b542418             mov edx, dword ptr [esp + 0x18]
// 008e7776  8b4024               mov eax, dword ptr [eax + 0x24]
// 008e7779  56                   push esi
// 008e777a  52                   push edx
// 008e777b  ffd0                 call eax
// 008e777d  8bf0                 mov esi, eax
// 008e777f  56                   push esi
// 008e7780  8d4c2410             lea ecx, [esp + 0x10]
// 008e7784  51                   push ecx
// 008e7785  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e7789  e870cef0ff           call 0x7f45fe
// 008e778e  8bc6                 mov eax, esi
// 008e7790  5e                   pop esi
// 008e7791  c21800               ret 0x18
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?FillPropertyButton@CXTPTabPaintManagerColorSet@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
