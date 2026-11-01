// from server: 100% by auto
// roc 2009-06 00758740  unit: CRobloxTreeCtrl  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00758740
//
// 00758740  8b442408             mov eax, dword ptr [esp + 8]
// 00758744  56                   push esi
// 00758745  f7d8                 neg eax
// 00758747  1bc0                 sbb eax, eax
// 00758749  6a10                 push 0x10
// 0075874b  8bf1                 mov esi, ecx
// 0075874d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00758751  83e010               and eax, 0x10
// 00758754  50                   push eax
// 00758755  51                   push ecx
// 00758756  8bce                 mov ecx, esi
// 00758758  e873ebffff           call 0x7572d0
// 0075875d  8b5634               mov edx, dword ptr [esi + 0x34]
// 00758760  8b4220               mov eax, dword ptr [edx + 0x20]
// 00758763  6a01                 push 1
// 00758765  6a00                 push 0
// 00758767  50                   push eax
// 00758768  ff157cee8900         call dword ptr [0x89ee7c]
// 0075876e  5e                   pop esi
// 0075876f  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SetItemBold@CXTPTreeBase@@UAEXPAU_TREEITEM@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
