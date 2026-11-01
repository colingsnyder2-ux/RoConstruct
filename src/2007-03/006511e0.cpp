// from server: 100% by auto
// roc 2007-03 006511e0  unit: seg_00650000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006511e0
//
// 006511e0  8a442404             mov al, byte ptr [esp + 4]
// 006511e4  a80a                 test al, 0xa
// 006511e6  742f                 je 0x651217
// 006511e8  807c240800           cmp byte ptr [esp + 8], 0
// 006511ed  752f                 jne 0x65121e
// 006511ef  a808                 test al, 8
// 006511f1  752b                 jne 0x65121e
// 006511f3  f644240c20           test byte ptr [esp + 0xc], 0x20
// 006511f8  741d                 je 0x651217
// 006511fa  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 006511fd  e8b89a0e00           call 0x73acba
// 00651202  85c0                 test eax, eax
// 00651204  7435                 je 0x65123b
// 00651206  e8953d0000           call 0x654fa0
// 0065120b  6a0f                 push 0xf
// 0065120d  8bc8                 mov ecx, eax
// 0065120f  e89c350000           call 0x6547b0
// 00651214  c21000               ret 0x10
// 00651217  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065121b  c21000               ret 0x10
// 0065121e  8b4934               mov ecx, dword ptr [ecx + 0x34]
// 00651221  e8949a0e00           call 0x73acba
// 00651226  85c0                 test eax, eax
// 00651228  7411                 je 0x65123b
// 0065122a  e8713d0000           call 0x654fa0
// 0065122f  6a0d                 push 0xd
// 00651231  8bc8                 mov ecx, eax
// 00651233  e878350000           call 0x6547b0
// 00651238  c21000               ret 0x10
// 0065123b  e8603d0000           call 0x654fa0
// 00651240  6a11                 push 0x11
// 00651242  8bc8                 mov ecx, eax
// 00651244  e867350000           call 0x6547b0
// 00651249  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?GetItemBackColor@CXTPTreeBase@@MBEKI_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
