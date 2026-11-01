// from server: 100% by auto
// roc 2009-06 00756760  unit: CRobloxTreeCtrl  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00756760
//
// 00756760  8a442404             mov al, byte ptr [esp + 4]
// 00756764  a80a                 test al, 0xa
// 00756766  742f                 je 0x756797
// 00756768  807c240800           cmp byte ptr [esp + 8], 0
// 0075676d  752f                 jne 0x75679e
// 0075676f  a808                 test al, 8
// 00756771  752b                 jne 0x75679e
// 00756773  f644240c20           test byte ptr [esp + 0xc], 0x20
// 00756778  741d                 je 0x756797
// 0075677a  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0075677d  e8b8590f00           call 0x84c13a
// 00756782  85c0                 test eax, eax
// 00756784  7435                 je 0x7567bb
// 00756786  e895e3ffff           call 0x754b20
// 0075678b  6a0f                 push 0xf
// 0075678d  8bc8                 mov ecx, eax
// 0075678f  e80cdbffff           call 0x7542a0
// 00756794  c21000               ret 0x10
// 00756797  8b442410             mov eax, dword ptr [esp + 0x10]
// 0075679b  c21000               ret 0x10
// 0075679e  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 007567a1  e894590f00           call 0x84c13a
// 007567a6  85c0                 test eax, eax
// 007567a8  7411                 je 0x7567bb
// 007567aa  e871e3ffff           call 0x754b20
// 007567af  6a0d                 push 0xd
// 007567b1  8bc8                 mov ecx, eax
// 007567b3  e8e8daffff           call 0x7542a0
// 007567b8  c21000               ret 0x10
// 007567bb  e860e3ffff           call 0x754b20
// 007567c0  6a11                 push 0x11
// 007567c2  8bc8                 mov ecx, eax
// 007567c4  e8d7daffff           call 0x7542a0
// 007567c9  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetItemBackColor@CXTPTreeBase@@MBEKI_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
