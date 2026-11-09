// from server: 100% by auto
// roc 2010-06 007e57d0  unit: CRobloxTreeCtrl  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e57d0
//
// 007e57d0  8a442404             mov al, byte ptr [esp + 4]
// 007e57d4  a80a                 test al, 0xa
// 007e57d6  742f                 je 0x7e5807
// 007e57d8  807c240800           cmp byte ptr [esp + 8], 0
// 007e57dd  752f                 jne 0x7e580e
// 007e57df  a808                 test al, 8
// 007e57e1  752b                 jne 0x7e580e
// 007e57e3  f644240c20           test byte ptr [esp + 0xc], 0x20
// 007e57e8  741d                 je 0x7e5807
// 007e57ea  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 007e57ed  e8f0771900           call 0x97cfe2
// 007e57f2  85c0                 test eax, eax
// 007e57f4  7435                 je 0x7e582b
// 007e57f6  e825e3ffff           call 0x7e3b20
// 007e57fb  6a08                 push 8
// 007e57fd  8bc8                 mov ecx, eax
// 007e57ff  e8acdaffff           call 0x7e32b0
// 007e5804  c21000               ret 0x10
// 007e5807  8b442410             mov eax, dword ptr [esp + 0x10]
// 007e580b  c21000               ret 0x10
// 007e580e  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 007e5811  e8cc771900           call 0x97cfe2
// 007e5816  85c0                 test eax, eax
// 007e5818  7411                 je 0x7e582b
// 007e581a  e801e3ffff           call 0x7e3b20
// 007e581f  6a0e                 push 0xe
// 007e5821  8bc8                 mov ecx, eax
// 007e5823  e888daffff           call 0x7e32b0
// 007e5828  c21000               ret 0x10
// 007e582b  e8f0e2ffff           call 0x7e3b20
// 007e5830  6a0f                 push 0xf
// 007e5832  8bc8                 mov ecx, eax
// 007e5834  e877daffff           call 0x7e32b0
// 007e5839  c21000               ret 0x10
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?GetItemTextColor@CXTTreeBase@@MBEKI_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
