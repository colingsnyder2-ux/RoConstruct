// from server: 100% by auto
// roc 2009-12 008881b0  unit: XTPPaintThemes::CXTPOfficeTheme  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008881b0
//
// 008881b0  8b442418             mov eax, dword ptr [esp + 0x18]
// 008881b4  f7d8                 neg eax
// 008881b6  1bc0                 sbb eax, eax
// 008881b8  83e00c               and eax, 0xc
// 008881bb  83c01e               add eax, 0x1e
// 008881be  50                   push eax
// 008881bf  e87c54f7ff           call 0x7fd640
// 008881c4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008881c8  8b542410             mov edx, dword ptr [esp + 0x10]
// 008881cc  50                   push eax
// 008881cd  8b442410             mov eax, dword ptr [esp + 0x10]
// 008881d1  51                   push ecx
// 008881d2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008881d6  52                   push edx
// 008881d7  50                   push eax
// 008881d8  51                   push ecx
// 008881d9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008881dd  e8b4e20900           call 0x926496
// 008881e2  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawPopupBarGripper@CXTPOfficeTheme@@MAEXPAVCDC@@HHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOfficeTheme.cpp
