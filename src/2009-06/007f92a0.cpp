// from server: 100% by auto
// roc 2009-06 007f92a0  unit: CXTPTabPaintManager  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f92a0
//
// 007f92a0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007f92a4  83f8ff               cmp eax, -1
// 007f92a7  741b                 je 0x7f92c4
// 007f92a9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007f92ad  8b542408             mov edx, dword ptr [esp + 8]
// 007f92b1  50                   push eax
// 007f92b2  8b442414             mov eax, dword ptr [esp + 0x14]
// 007f92b6  50                   push eax
// 007f92b7  6a01                 push 1
// 007f92b9  51                   push ecx
// 007f92ba  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007f92be  52                   push edx
// 007f92bf  e86c2c0500           call 0x84bf30
// 007f92c4  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?VerticalLine@@YAXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
