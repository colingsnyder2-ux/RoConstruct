// from server: 100% by auto
// roc 2009-12 008d3e70  unit: CXTPTabPaintManager  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d3e70
//
// 008d3e70  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d3e74  83f8ff               cmp eax, -1
// 008d3e77  741b                 je 0x8d3e94
// 008d3e79  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008d3e7d  8b542408             mov edx, dword ptr [esp + 8]
// 008d3e81  50                   push eax
// 008d3e82  8b442414             mov eax, dword ptr [esp + 0x14]
// 008d3e86  6a01                 push 1
// 008d3e88  50                   push eax
// 008d3e89  51                   push ecx
// 008d3e8a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008d3e8e  52                   push edx
// 008d3e8f  e802260500           call 0x926496
// 008d3e94  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?HorizontalLine@@YAXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
