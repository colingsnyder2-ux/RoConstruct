// from server: 100% by auto
// roc 2009-06 00797ad0  unit: CXTPRibbonTheme  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00797ad0
//
// 00797ad0  56                   push esi
// 00797ad1  6a38                 push 0x38
// 00797ad3  e8a8acf8ff           call 0x722780
// 00797ad8  8b742408             mov esi, dword ptr [esp + 8]
// 00797adc  50                   push eax
// 00797add  8d442410             lea eax, [esp + 0x10]
// 00797ae1  50                   push eax
// 00797ae2  8bce                 mov ecx, esi
// 00797ae4  e8e71cf8ff           call 0x7197d0
// 00797ae9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00797aed  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00797af1  8b542418             mov edx, dword ptr [esp + 0x18]
// 00797af5  68c5c5c500           push 0xc5c5c5
// 00797afa  6a01                 push 1
// 00797afc  2bc8                 sub ecx, eax
// 00797afe  51                   push ecx
// 00797aff  4a                   dec edx
// 00797b00  52                   push edx
// 00797b01  50                   push eax
// 00797b02  8bce                 mov ecx, esi
// 00797b04  e827440b00           call 0x84bf30
// 00797b09  5e                   pop esi
// 00797b0a  c21400               ret 0x14
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?FillPopupLabelEntry@CXTPRibbonTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTheme.cpp
