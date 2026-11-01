// from server: 100% by auto
// roc 2009-06 007229e0  unit: CXTPPaintManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007229e0
//
// 007229e0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007229e4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007229e8  8b542408             mov edx, dword ptr [esp + 8]
// 007229ec  50                   push eax
// 007229ed  8b442410             mov eax, dword ptr [esp + 0x10]
// 007229f1  2bc8                 sub ecx, eax
// 007229f3  51                   push ecx
// 007229f4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007229f8  6a01                 push 1
// 007229fa  50                   push eax
// 007229fb  52                   push edx
// 007229fc  e82f951200           call 0x84bf30
// 00722a01  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?VerticalLine@CXTPPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
