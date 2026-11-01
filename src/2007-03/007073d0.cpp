// from server: 100% by auto
// roc 2007-03 007073d0  unit: seg_00700000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007073d0
//
// 007073d0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007073d4  83f8ff               cmp eax, -1
// 007073d7  741b                 je 0x7073f4
// 007073d9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007073dd  8b542408             mov edx, dword ptr [esp + 8]
// 007073e1  50                   push eax
// 007073e2  8b442414             mov eax, dword ptr [esp + 0x14]
// 007073e6  6a01                 push 1
// 007073e8  50                   push eax
// 007073e9  51                   push ecx
// 007073ea  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007073ee  52                   push edx
// 007073ef  e8f8360300           call 0x73aaec
// 007073f4  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?HorizontalLine@@YAXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
