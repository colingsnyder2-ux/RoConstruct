// from server: 100% by auto
// roc 2010-06 0083c540  unit: XTPPaintThemes::CXTPOfficeTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0083c540
//
// 0083c540  6a38                 push 0x38
// 0083c542  e8c90bf7ff           call 0x7ad110
// 0083c547  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0083c54b  50                   push eax
// 0083c54c  8d44240c             lea eax, [esp + 0xc]
// 0083c550  50                   push eax
// 0083c551  e8e8c1f6ff           call 0x7a873e
// 0083c556  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?FillPopupLabelEntry@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
