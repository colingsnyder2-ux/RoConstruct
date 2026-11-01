// from server: 100% by auto
// roc 2007-03 00685d60  unit: seg_00680000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00685d60
//
// 00685d60  33c0                 xor eax, eax
// 00685d62  83791001             cmp dword ptr [ecx + 0x10], 1
// 00685d66  0f94c0               sete al
// 00685d69  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsWin9x@CXTPSystemVersion@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
