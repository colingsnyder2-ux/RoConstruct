// from server: 100% by auto
// roc 2009-12 008d3e40  unit: CXTPTabPaintManager  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d3e40
//
// 008d3e40  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d3e44  83f8ff               cmp eax, -1
// 008d3e47  741b                 je 0x8d3e64
// 008d3e49  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d3e4d  8b542408             mov edx, dword ptr [esp + 8]
// 008d3e51  50                   push eax
// 008d3e52  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d3e56  50                   push eax
// 008d3e57  6a01                 push 1
// 008d3e59  51                   push ecx
// 008d3e5a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d3e5e  52                   push edx
// 008d3e5f  e832260500           call 0x926496
// 008d3e64  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?VerticalLine@@YAXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
