// from server: 100% by auto
// roc 2010-06 007ef920  unit: CXTPToolBar::CControlButtonExpand  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ef920
//
// 007ef920  8b4104               mov eax, dword ptr [ecx + 4]
// 007ef923  3b442404             cmp eax, dword ptr [esp + 4]
// 007ef927  7511                 jne 0x7ef93a
// 007ef929  8b4908               mov ecx, dword ptr [ecx + 8]
// 007ef92c  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 007ef930  7508                 jne 0x7ef93a
// 007ef932  b801000000           mov eax, 1
// 007ef937  c20800               ret 8
// 007ef93a  33c0                 xor eax, eax
// 007ef93c  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?EqualTo@CXTPSystemVersion@@ABE_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
