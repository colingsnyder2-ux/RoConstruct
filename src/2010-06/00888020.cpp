// from server: 100% by auto
// roc 2010-06 00888020  unit: CXTPTabPaintManager  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00888020
//
// 00888020  8b442414             mov eax, dword ptr [esp + 0x14]
// 00888024  83f8ff               cmp eax, -1
// 00888027  741b                 je 0x888044
// 00888029  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0088802d  8b542408             mov edx, dword ptr [esp + 8]
// 00888031  50                   push eax
// 00888032  8b442414             mov eax, dword ptr [esp + 0x14]
// 00888036  6a01                 push 1
// 00888038  50                   push eax
// 00888039  51                   push ecx
// 0088803a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0088803e  52                   push edx
// 0088803f  e8464d0f00           call 0x97cd8a
// 00888044  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?HorizontalLine@@YAXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
