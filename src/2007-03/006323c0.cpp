// from server: 100% by auto
// roc 2007-03 006323c0  unit: seg_00630000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006323c0
//
// 006323c0  8b442414             mov eax, dword ptr [esp + 0x14]
// 006323c4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006323c8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006323cc  50                   push eax
// 006323cd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006323d1  6a01                 push 1
// 006323d3  2bc8                 sub ecx, eax
// 006323d5  51                   push ecx
// 006323d6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006323da  52                   push edx
// 006323db  50                   push eax
// 006323dc  e80b871000           call 0x73aaec
// 006323e1  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?HorizontalLine@CXTPPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
