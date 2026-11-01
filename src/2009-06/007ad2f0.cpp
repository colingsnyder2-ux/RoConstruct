// from server: 100% by auto
// roc 2009-06 007ad2f0  unit: XTPPaintThemes::CXTPOfficeTheme  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ad2f0
//
// 007ad2f0  8b442418             mov eax, dword ptr [esp + 0x18]
// 007ad2f4  f7d8                 neg eax
// 007ad2f6  1bc0                 sbb eax, eax
// 007ad2f8  83e00c               and eax, 0xc
// 007ad2fb  83c01e               add eax, 0x1e
// 007ad2fe  50                   push eax
// 007ad2ff  e87c54f7ff           call 0x722780
// 007ad304  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007ad308  8b542410             mov edx, dword ptr [esp + 0x10]
// 007ad30c  50                   push eax
// 007ad30d  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ad311  51                   push ecx
// 007ad312  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007ad316  52                   push edx
// 007ad317  50                   push eax
// 007ad318  51                   push ecx
// 007ad319  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007ad31d  e80eec0900           call 0x84bf30
// 007ad322  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawPopupBarGripper@CXTPOfficeTheme@@MAEXPAVCDC@@HHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOfficeTheme.cpp
