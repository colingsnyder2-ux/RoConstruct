// from server: 100% by auto
// roc 2007-03 00651250  unit: seg_00650000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00651250
//
// 00651250  8a442404             mov al, byte ptr [esp + 4]
// 00651254  a80a                 test al, 0xa
// 00651256  742f                 je 0x651287
// 00651258  807c240800           cmp byte ptr [esp + 8], 0
// 0065125d  752f                 jne 0x65128e
// 0065125f  a808                 test al, 8
// 00651261  752b                 jne 0x65128e
// 00651263  f644240c20           test byte ptr [esp + 0xc], 0x20
// 00651268  741d                 je 0x651287
// 0065126a  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 0065126d  e8489a0e00           call 0x73acba
// 00651272  85c0                 test eax, eax
// 00651274  7435                 je 0x6512ab
// 00651276  e8253d0000           call 0x654fa0
// 0065127b  6a08                 push 8
// 0065127d  8bc8                 mov ecx, eax
// 0065127f  e82c350000           call 0x6547b0
// 00651284  c21000               ret 0x10
// 00651287  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065128b  c21000               ret 0x10
// 0065128e  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 00651291  e8249a0e00           call 0x73acba
// 00651296  85c0                 test eax, eax
// 00651298  7411                 je 0x6512ab
// 0065129a  e8013d0000           call 0x654fa0
// 0065129f  6a0e                 push 0xe
// 006512a1  8bc8                 mov ecx, eax
// 006512a3  e808350000           call 0x6547b0
// 006512a8  c21000               ret 0x10
// 006512ab  e8f03c0000           call 0x654fa0
// 006512b0  6a0f                 push 0xf
// 006512b2  8bc8                 mov ecx, eax
// 006512b4  e8f7340000           call 0x6547b0
// 006512b9  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetItemTextColor@CXTPTreeBase@@MBEKI_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
