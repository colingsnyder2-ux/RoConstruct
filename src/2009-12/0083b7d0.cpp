// from server: 100% by auto
// roc 2009-12 0083b7d0  unit: CXTPToolBar::CControlButtonExpand  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b7d0
//
// 0083b7d0  8b4104               mov eax, dword ptr [ecx + 4]
// 0083b7d3  3b442404             cmp eax, dword ptr [esp + 4]
// 0083b7d7  7511                 jne 0x83b7ea
// 0083b7d9  8b4908               mov ecx, dword ptr [ecx + 8]
// 0083b7dc  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 0083b7e0  7508                 jne 0x83b7ea
// 0083b7e2  b801000000           mov eax, 1
// 0083b7e7  c20800               ret 8
// 0083b7ea  33c0                 xor eax, eax
// 0083b7ec  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?EqualTo@CXTPSystemVersion@@ABE_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
