// from server: 100% by auto
// roc 2009-12 00831680  unit: CRobloxTreeCtrl  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00831680
//
// 00831680  8a442404             mov al, byte ptr [esp + 4]
// 00831684  a80a                 test al, 0xa
// 00831686  742f                 je 0x8316b7
// 00831688  807c240800           cmp byte ptr [esp + 8], 0
// 0083168d  752f                 jne 0x8316be
// 0083168f  a808                 test al, 8
// 00831691  752b                 jne 0x8316be
// 00831693  f644240c20           test byte ptr [esp + 0xc], 0x20
// 00831698  741d                 je 0x8316b7
// 0083169a  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0083169d  e804500f00           call 0x9266a6
// 008316a2  85c0                 test eax, eax
// 008316a4  7435                 je 0x8316db
// 008316a6  e825e3ffff           call 0x82f9d0
// 008316ab  6a08                 push 8
// 008316ad  8bc8                 mov ecx, eax
// 008316af  e84cdaffff           call 0x82f100
// 008316b4  c21000               ret 0x10
// 008316b7  8b442410             mov eax, dword ptr [esp + 0x10]
// 008316bb  c21000               ret 0x10
// 008316be  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 008316c1  e8e04f0f00           call 0x9266a6
// 008316c6  85c0                 test eax, eax
// 008316c8  7411                 je 0x8316db
// 008316ca  e801e3ffff           call 0x82f9d0
// 008316cf  6a0e                 push 0xe
// 008316d1  8bc8                 mov ecx, eax
// 008316d3  e828daffff           call 0x82f100
// 008316d8  c21000               ret 0x10
// 008316db  e8f0e2ffff           call 0x82f9d0
// 008316e0  6a0f                 push 0xf
// 008316e2  8bc8                 mov ecx, eax
// 008316e4  e817daffff           call 0x82f100
// 008316e9  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetItemTextColor@CXTPTreeBase@@MBEKI_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
