// from server: 100% by auto
// roc 2010-06 00887ff0  unit: CXTPTabPaintManager  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00887ff0
//
// 00887ff0  8b442414             mov eax, dword ptr [esp + 0x14]
// 00887ff4  83f8ff               cmp eax, -1
// 00887ff7  741b                 je 0x888014
// 00887ff9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00887ffd  8b542408             mov edx, dword ptr [esp + 8]
// 00888001  50                   push eax
// 00888002  8b442414             mov eax, dword ptr [esp + 0x14]
// 00888006  50                   push eax
// 00888007  6a01                 push 1
// 00888009  51                   push ecx
// 0088800a  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0088800e  52                   push edx
// 0088800f  e8764d0f00           call 0x97cd8a
// 00888014  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManagerAppearance.cpp (function ?VerticalLine@@YAXPAVCDC@@HHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerAppearance.cpp
