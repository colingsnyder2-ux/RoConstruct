// from server: 100% by auto
// roc 2009-12 00888fc0  unit: XTPPaintThemes::CXTPOfficeTheme  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00888fc0
//
// 00888fc0  6a38                 push 0x38
// 00888fc2  e87946f7ff           call 0x7fd640
// 00888fc7  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00888fcb  50                   push eax
// 00888fcc  8d44240c             lea eax, [esp + 0xc]
// 00888fd0  50                   push eax
// 00888fd1  e828b6f6ff           call 0x7f45fe
// 00888fd6  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?FillPopupLabelEntry@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOfficeTheme.cpp
