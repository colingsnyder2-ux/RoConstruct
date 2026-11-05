// from server: 100% by auto
// roc 2010-06 007ef8d0  unit: CXTPToolBar::CControlButtonExpand  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ef8d0
//
// 007ef8d0  83791002             cmp dword ptr [ecx + 0x10], 2
// 007ef8d4  720c                 jb 0x7ef8e2
// 007ef8d6  83790405             cmp dword ptr [ecx + 4], 5
// 007ef8da  7206                 jb 0x7ef8e2
// 007ef8dc  b801000000           mov eax, 1
// 007ef8e1  c3                   ret 
// 007ef8e2  33c0                 xor eax, eax
// 007ef8e4  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsWin2KOrGreater@CXTPSystemVersion@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
