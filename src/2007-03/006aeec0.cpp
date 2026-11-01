// from server: 100% by auto
// roc 2007-03 006aeec0  unit: seg_006a0000  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006aeec0
//
// 006aeec0  8b442418             mov eax, dword ptr [esp + 0x18]
// 006aeec4  f7d8                 neg eax
// 006aeec6  1bc0                 sbb eax, eax
// 006aeec8  83e00c               and eax, 0xc
// 006aeecb  83c01e               add eax, 0x1e
// 006aeece  50                   push eax
// 006aeecf  e8cc32f8ff           call 0x6321a0
// 006aeed4  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006aeed8  8b542410             mov edx, dword ptr [esp + 0x10]
// 006aeedc  50                   push eax
// 006aeedd  8b442410             mov eax, dword ptr [esp + 0x10]
// 006aeee1  51                   push ecx
// 006aeee2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006aeee6  52                   push edx
// 006aeee7  50                   push eax
// 006aeee8  51                   push ecx
// 006aeee9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006aeeed  e8fabb0800           call 0x73aaec
// 006aeef2  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?DrawPopupBarGripper@CXTPOfficeTheme@@MAEXPAVCDC@@HHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOfficeTheme.cpp
