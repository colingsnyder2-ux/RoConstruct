// from server: 100% by auto
// roc 2009-12 0083b770  unit: CXTPToolBar::CControlButtonExpand  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b770
//
// 0083b770  33c0                 xor eax, eax
// 0083b772  83791001             cmp dword ptr [ecx + 0x10], 1
// 0083b776  0f94c0               sete al
// 0083b779  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsWin9x@CXTPSystemVersion@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
