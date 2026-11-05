// from server: 100% by auto
// roc 2010-06 0082f3a0  unit: CXTPRibbonTheme  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0082f3a0
//
// 0082f3a0  56                   push esi
// 0082f3a1  6a38                 push 0x38
// 0082f3a3  e868ddf7ff           call 0x7ad110
// 0082f3a8  8b742408             mov esi, dword ptr [esp + 8]
// 0082f3ac  50                   push eax
// 0082f3ad  8d442410             lea eax, [esp + 0x10]
// 0082f3b1  50                   push eax
// 0082f3b2  8bce                 mov ecx, esi
// 0082f3b4  e88593f7ff           call 0x7a873e
// 0082f3b9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0082f3bd  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0082f3c1  8b542418             mov edx, dword ptr [esp + 0x18]
// 0082f3c5  68c5c5c500           push 0xc5c5c5
// 0082f3ca  6a01                 push 1
// 0082f3cc  2bc8                 sub ecx, eax
// 0082f3ce  51                   push ecx
// 0082f3cf  4a                   dec edx
// 0082f3d0  52                   push edx
// 0082f3d1  50                   push eax
// 0082f3d2  8bce                 mov ecx, esi
// 0082f3d4  e8b1d91400           call 0x97cd8a
// 0082f3d9  5e                   pop esi
// 0082f3da  c21400               ret 0x14
// library xtp-13.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?FillPopupLabelEntry@CXTPRibbonTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonTheme.cpp
