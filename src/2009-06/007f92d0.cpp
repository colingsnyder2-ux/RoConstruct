// from server: 100% by auto
// roc 2009-06 007f92d0  unit: CXTPTabPaintManager  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f92d0
//
// 007f92d0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007f92d4  83f8ff               cmp eax, -1
// 007f92d7  741b                 je 0x7f92f4
// 007f92d9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007f92dd  8b542408             mov edx, dword ptr [esp + 8]
// 007f92e1  50                   push eax
// 007f92e2  8b442414             mov eax, dword ptr [esp + 0x14]
// 007f92e6  6a01                 push 1
// 007f92e8  50                   push eax
// 007f92e9  51                   push ecx
// 007f92ea  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007f92ee  52                   push edx
// 007f92ef  e83c2c0500           call 0x84bf30
// 007f92f4  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?HorizontalLine@@YAXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
