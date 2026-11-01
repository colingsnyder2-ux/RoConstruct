// from server: 100% by auto
// roc 2009-06 007229b0  unit: CXTPPaintManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007229b0
//
// 007229b0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007229b4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007229b8  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007229bc  50                   push eax
// 007229bd  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007229c1  6a01                 push 1
// 007229c3  2bc8                 sub ecx, eax
// 007229c5  51                   push ecx
// 007229c6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007229ca  52                   push edx
// 007229cb  50                   push eax
// 007229cc  e85f951200           call 0x84bf30
// 007229d1  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?HorizontalLine@CXTPPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
