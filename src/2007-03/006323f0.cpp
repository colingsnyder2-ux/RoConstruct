// from server: 100% by auto
// roc 2007-03 006323f0  unit: seg_00630000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006323f0
//
// 006323f0  8b442414             mov eax, dword ptr [esp + 0x14]
// 006323f4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006323f8  8b542408             mov edx, dword ptr [esp + 8]
// 006323fc  50                   push eax
// 006323fd  8b442410             mov eax, dword ptr [esp + 0x10]
// 00632401  2bc8                 sub ecx, eax
// 00632403  51                   push ecx
// 00632404  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00632408  6a01                 push 1
// 0063240a  50                   push eax
// 0063240b  52                   push edx
// 0063240c  e8db861000           call 0x73aaec
// 00632411  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?VerticalLine@CXTPPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
