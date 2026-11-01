// from server: 100% by auto
// roc 2009-12 007fd8a0  unit: CXTPPaintManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fd8a0
//
// 007fd8a0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fd8a4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007fd8a8  8b542408             mov edx, dword ptr [esp + 8]
// 007fd8ac  50                   push eax
// 007fd8ad  8b442410             mov eax, dword ptr [esp + 0x10]
// 007fd8b1  2bc8                 sub ecx, eax
// 007fd8b3  51                   push ecx
// 007fd8b4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007fd8b8  6a01                 push 1
// 007fd8ba  50                   push eax
// 007fd8bb  52                   push edx
// 007fd8bc  e8d58b1200           call 0x926496
// 007fd8c1  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?VerticalLine@CXTPPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
