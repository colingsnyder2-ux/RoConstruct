// from server: 100% by auto
// roc 2010-06 007e5760  unit: CRobloxTreeCtrl  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e5760
//
// 007e5760  8a442404             mov al, byte ptr [esp + 4]
// 007e5764  a80a                 test al, 0xa
// 007e5766  742f                 je 0x7e5797
// 007e5768  807c240800           cmp byte ptr [esp + 8], 0
// 007e576d  752f                 jne 0x7e579e
// 007e576f  a808                 test al, 8
// 007e5771  752b                 jne 0x7e579e
// 007e5773  f644240c20           test byte ptr [esp + 0xc], 0x20
// 007e5778  741d                 je 0x7e5797
// 007e577a  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 007e577d  e860781900           call 0x97cfe2
// 007e5782  85c0                 test eax, eax
// 007e5784  7435                 je 0x7e57bb
// 007e5786  e895e3ffff           call 0x7e3b20
// 007e578b  6a0f                 push 0xf
// 007e578d  8bc8                 mov ecx, eax
// 007e578f  e81cdbffff           call 0x7e32b0
// 007e5794  c21000               ret 0x10
// 007e5797  8b442410             mov eax, dword ptr [esp + 0x10]
// 007e579b  c21000               ret 0x10
// 007e579e  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 007e57a1  e83c781900           call 0x97cfe2
// 007e57a6  85c0                 test eax, eax
// 007e57a8  7411                 je 0x7e57bb
// 007e57aa  e871e3ffff           call 0x7e3b20
// 007e57af  6a0d                 push 0xd
// 007e57b1  8bc8                 mov ecx, eax
// 007e57b3  e8f8daffff           call 0x7e32b0
// 007e57b8  c21000               ret 0x10
// 007e57bb  e860e3ffff           call 0x7e3b20
// 007e57c0  6a11                 push 0x11
// 007e57c2  8bc8                 mov ecx, eax
// 007e57c4  e8e7daffff           call 0x7e32b0
// 007e57c9  c21000               ret 0x10
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetItemBackColor@CXTTreeBase@@MBEKI_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
