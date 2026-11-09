// from server: 100% by auto
// roc 2010-06 007ad370  unit: CXTPPaintManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ad370
//
// 007ad370  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ad374  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007ad378  8b542408             mov edx, dword ptr [esp + 8]
// 007ad37c  50                   push eax
// 007ad37d  8b442410             mov eax, dword ptr [esp + 0x10]
// 007ad381  2bc8                 sub ecx, eax
// 007ad383  51                   push ecx
// 007ad384  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007ad388  6a01                 push 1
// 007ad38a  50                   push eax
// 007ad38b  52                   push edx
// 007ad38c  e8f9f91c00           call 0x97cd8a
// 007ad391  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?VerticalLine@CXTPPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
