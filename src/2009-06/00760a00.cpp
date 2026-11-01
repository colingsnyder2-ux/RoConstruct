// from server: 100% by auto
// roc 2009-06 00760a00  unit: CXTPToolBar::CControlButtonExpand  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760a00
//
// 00760a00  8b4104               mov eax, dword ptr [ecx + 4]
// 00760a03  3b442404             cmp eax, dword ptr [esp + 4]
// 00760a07  7511                 jne 0x760a1a
// 00760a09  8b4908               mov ecx, dword ptr [ecx + 8]
// 00760a0c  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 00760a10  7508                 jne 0x760a1a
// 00760a12  b801000000           mov eax, 1
// 00760a17  c20800               ret 8
// 00760a1a  33c0                 xor eax, eax
// 00760a1c  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?EqualTo@CXTPSystemVersion@@ABE_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
