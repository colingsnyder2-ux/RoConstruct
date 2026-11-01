// from server: 100% by auto
// roc 2009-12 007fd870  unit: CXTPPaintManager  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fd870
//
// 007fd870  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fd874  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007fd878  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007fd87c  50                   push eax
// 007fd87d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007fd881  6a01                 push 1
// 007fd883  2bc8                 sub ecx, eax
// 007fd885  51                   push ecx
// 007fd886  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007fd88a  52                   push edx
// 007fd88b  50                   push eax
// 007fd88c  e8058c1200           call 0x926496
// 007fd891  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?HorizontalLine@CXTPPaintManager@@QAEXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
