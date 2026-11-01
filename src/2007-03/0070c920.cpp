// from server: 100% by auto
// roc 2007-03 0070c920  unit: seg_00700000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0070c920
//
// 0070c920  8b01                 mov eax, dword ptr [ecx]
// 0070c922  8b542418             mov edx, dword ptr [esp + 0x18]
// 0070c926  8b4024               mov eax, dword ptr [eax + 0x24]
// 0070c929  56                   push esi
// 0070c92a  52                   push edx
// 0070c92b  ffd0                 call eax
// 0070c92d  8bf0                 mov esi, eax
// 0070c92f  56                   push esi
// 0070c930  8d4c2410             lea ecx, [esp + 0x10]
// 0070c934  51                   push ecx
// 0070c935  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0070c939  e8dc23f1ff           call 0x61ed1a
// 0070c93e  8bc6                 mov eax, esi
// 0070c940  5e                   pop esi
// 0070c941  c21800               ret 0x18
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerColors.cpp (function ?FillPropertyButton@CXTPTabPaintManagerColorSet@@UAEKPAVCDC@@VCRect@@PAVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp
