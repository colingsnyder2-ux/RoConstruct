// from server: 100% by auto
// roc 2010-06 007ad340  unit: CXTPPaintManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ad340
//
// 007ad340  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ad344  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007ad348  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007ad34c  50                   push eax
// 007ad34d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007ad351  6a01                 push 1
// 007ad353  2bc8                 sub ecx, eax
// 007ad355  51                   push ecx
// 007ad356  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007ad35a  52                   push edx
// 007ad35b  50                   push eax
// 007ad35c  e829fa1c00           call 0x97cd8a
// 007ad361  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?HorizontalLine@CXTPPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
