// from server: 100% by auto
// roc 2007-03 00653100  unit: seg_00650000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00653100
//
// 00653100  8b442408             mov eax, dword ptr [esp + 8]
// 00653104  56                   push esi
// 00653105  f7d8                 neg eax
// 00653107  1bc0                 sbb eax, eax
// 00653109  6a10                 push 0x10
// 0065310b  8bf1                 mov esi, ecx
// 0065310d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00653111  83e010               and eax, 0x10
// 00653114  50                   push eax
// 00653115  51                   push ecx
// 00653116  8bce                 mov ecx, esi
// 00653118  e8e3ebffff           call 0x651d00
// 0065311d  8b5634               mov edx, dword ptr [esi + 0x34]
// 00653120  8b4220               mov eax, dword ptr [edx + 0x20]
// 00653123  6a01                 push 1
// 00653125  6a00                 push 0
// 00653127  50                   push eax
// 00653128  ff1554ee7700         call dword ptr [0x77ee54]
// 0065312e  5e                   pop esi
// 0065312f  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?SetItemBold@CXTPTreeBase@@UAEXPAU_TREEITEM@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
