// from server: 100% by auto
// roc 2009-12 00831610  unit: CRobloxTreeCtrl  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00831610
//
// 00831610  8a442404             mov al, byte ptr [esp + 4]
// 00831614  a80a                 test al, 0xa
// 00831616  742f                 je 0x831647
// 00831618  807c240800           cmp byte ptr [esp + 8], 0
// 0083161d  752f                 jne 0x83164e
// 0083161f  a808                 test al, 8
// 00831621  752b                 jne 0x83164e
// 00831623  f644240c20           test byte ptr [esp + 0xc], 0x20
// 00831628  741d                 je 0x831647
// 0083162a  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0083162d  e874500f00           call 0x9266a6
// 00831632  85c0                 test eax, eax
// 00831634  7435                 je 0x83166b
// 00831636  e895e3ffff           call 0x82f9d0
// 0083163b  6a0f                 push 0xf
// 0083163d  8bc8                 mov ecx, eax
// 0083163f  e8bcdaffff           call 0x82f100
// 00831644  c21000               ret 0x10
// 00831647  8b442410             mov eax, dword ptr [esp + 0x10]
// 0083164b  c21000               ret 0x10
// 0083164e  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 00831651  e850500f00           call 0x9266a6
// 00831656  85c0                 test eax, eax
// 00831658  7411                 je 0x83166b
// 0083165a  e871e3ffff           call 0x82f9d0
// 0083165f  6a0d                 push 0xd
// 00831661  8bc8                 mov ecx, eax
// 00831663  e898daffff           call 0x82f100
// 00831668  c21000               ret 0x10
// 0083166b  e860e3ffff           call 0x82f9d0
// 00831670  6a11                 push 0x11
// 00831672  8bc8                 mov ecx, eax
// 00831674  e887daffff           call 0x82f100
// 00831679  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetItemBackColor@CXTPTreeBase@@MBEKI_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
