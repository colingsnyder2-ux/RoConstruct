// from server: 100% by auto
// roc 2007-03 007073a0  unit: seg_00700000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007073a0
//
// 007073a0  8b442414             mov eax, dword ptr [esp + 0x14]
// 007073a4  83f8ff               cmp eax, -1
// 007073a7  741b                 je 0x7073c4
// 007073a9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007073ad  8b542408             mov edx, dword ptr [esp + 8]
// 007073b1  50                   push eax
// 007073b2  8b442414             mov eax, dword ptr [esp + 0x14]
// 007073b6  50                   push eax
// 007073b7  6a01                 push 1
// 007073b9  51                   push ecx
// 007073ba  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007073be  52                   push edx
// 007073bf  e828370300           call 0x73aaec
// 007073c4  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?VerticalLine@@YAXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
