// from server: 100% by auto
// roc 2009-06 007ae100  unit: XTPPaintThemes::CXTPOfficeTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ae100
//
// 007ae100  6a38                 push 0x38
// 007ae102  e87946f7ff           call 0x722780
// 007ae107  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007ae10b  50                   push eax
// 007ae10c  8d44240c             lea eax, [esp + 0xc]
// 007ae110  50                   push eax
// 007ae111  e8bab6f6ff           call 0x7197d0
// 007ae116  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?FillPopupLabelEntry@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOfficeTheme.cpp
