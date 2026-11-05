// from server: 100% by auto
// roc 2010-06 0083b710  unit: XTPPaintThemes::CXTPOfficeTheme  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0083b710
//
// 0083b710  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083b714  f7d8                 neg eax
// 0083b716  1bc0                 sbb eax, eax
// 0083b718  83e00c               and eax, 0xc
// 0083b71b  83c01e               add eax, 0x1e
// 0083b71e  50                   push eax
// 0083b71f  e8ec19f7ff           call 0x7ad110
// 0083b724  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0083b728  8b542410             mov edx, dword ptr [esp + 0x10]
// 0083b72c  50                   push eax
// 0083b72d  8b442410             mov eax, dword ptr [esp + 0x10]
// 0083b731  51                   push ecx
// 0083b732  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0083b736  52                   push edx
// 0083b737  50                   push eax
// 0083b738  51                   push ecx
// 0083b739  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0083b73d  e848161400           call 0x97cd8a
// 0083b742  c21800               ret 0x18
// library xtp-13.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawPopupBarGripper@CXTPOfficeTheme@@MAEXPAVCDC@@HHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOfficeTheme.cpp
