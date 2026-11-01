// from server: 100% by auto
// roc 2009-12 008335c0  unit: CRobloxTreeCtrl  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008335c0
//
// 008335c0  8b442408             mov eax, dword ptr [esp + 8]
// 008335c4  56                   push esi
// 008335c5  f7d8                 neg eax
// 008335c7  1bc0                 sbb eax, eax
// 008335c9  6a10                 push 0x10
// 008335cb  8bf1                 mov esi, ecx
// 008335cd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008335d1  83e010               and eax, 0x10
// 008335d4  50                   push eax
// 008335d5  51                   push ecx
// 008335d6  8bce                 mov ecx, esi
// 008335d8  e873ebffff           call 0x832150
// 008335dd  8b5634               mov edx, dword ptr [esi + 0x34]
// 008335e0  8b4220               mov eax, dword ptr [edx + 0x20]
// 008335e3  6a01                 push 1
// 008335e5  6a00                 push 0
// 008335e7  50                   push eax
// 008335e8  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008335ee  5e                   pop esi
// 008335ef  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SetItemBold@CXTPTreeBase@@UAEXPAU_TREEITEM@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
