// from server: 100% by auto
// roc 2009-12 00874470  unit: CXTPRibbonTheme  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00874470
//
// 00874470  56                   push esi
// 00874471  6a38                 push 0x38
// 00874473  e8c891f8ff           call 0x7fd640
// 00874478  8b742408             mov esi, dword ptr [esp + 8]
// 0087447c  50                   push eax
// 0087447d  8d442410             lea eax, [esp + 0x10]
// 00874481  50                   push eax
// 00874482  8bce                 mov ecx, esi
// 00874484  e87501f8ff           call 0x7f45fe
// 00874489  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0087448d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00874491  8b542418             mov edx, dword ptr [esp + 0x18]
// 00874495  68c5c5c500           push 0xc5c5c5
// 0087449a  6a01                 push 1
// 0087449c  2bc8                 sub ecx, eax
// 0087449e  51                   push ecx
// 0087449f  4a                   dec edx
// 008744a0  52                   push edx
// 008744a1  50                   push eax
// 008744a2  8bce                 mov ecx, esi
// 008744a4  e8ed1f0b00           call 0x926496
// 008744a9  5e                   pop esi
// 008744aa  c21400               ret 0x14
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?FillPopupLabelEntry@CXTPRibbonTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTheme.cpp
