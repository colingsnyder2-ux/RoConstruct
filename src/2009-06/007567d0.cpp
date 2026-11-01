// from server: 100% by auto
// roc 2009-06 007567d0  unit: CRobloxTreeCtrl  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007567d0
//
// 007567d0  8a442404             mov al, byte ptr [esp + 4]
// 007567d4  a80a                 test al, 0xa
// 007567d6  742f                 je 0x756807
// 007567d8  807c240800           cmp byte ptr [esp + 8], 0
// 007567dd  752f                 jne 0x75680e
// 007567df  a808                 test al, 8
// 007567e1  752b                 jne 0x75680e
// 007567e3  f644240c20           test byte ptr [esp + 0xc], 0x20
// 007567e8  741d                 je 0x756807
// 007567ea  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 007567ed  e848590f00           call 0x84c13a
// 007567f2  85c0                 test eax, eax
// 007567f4  7435                 je 0x75682b
// 007567f6  e825e3ffff           call 0x754b20
// 007567fb  6a08                 push 8
// 007567fd  8bc8                 mov ecx, eax
// 007567ff  e89cdaffff           call 0x7542a0
// 00756804  c21000               ret 0x10
// 00756807  8b442410             mov eax, dword ptr [esp + 0x10]
// 0075680b  c21000               ret 0x10
// 0075680e  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 00756811  e824590f00           call 0x84c13a
// 00756816  85c0                 test eax, eax
// 00756818  7411                 je 0x75682b
// 0075681a  e801e3ffff           call 0x754b20
// 0075681f  6a0e                 push 0xe
// 00756821  8bc8                 mov ecx, eax
// 00756823  e878daffff           call 0x7542a0
// 00756828  c21000               ret 0x10
// 0075682b  e8f0e2ffff           call 0x754b20
// 00756830  6a0f                 push 0xf
// 00756832  8bc8                 mov ecx, eax
// 00756834  e867daffff           call 0x7542a0
// 00756839  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetItemTextColor@CXTPTreeBase@@MBEKI_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
