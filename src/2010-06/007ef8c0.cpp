// from server: 100% by auto
// roc 2010-06 007ef8c0  unit: CXTPToolBar::CControlButtonExpand  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ef8c0
//
// 007ef8c0  33c0                 xor eax, eax
// 007ef8c2  83791001             cmp dword ptr [ecx + 0x10], 1
// 007ef8c6  0f94c0               sete al
// 007ef8c9  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsWin9x@CXTPSystemVersion@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
