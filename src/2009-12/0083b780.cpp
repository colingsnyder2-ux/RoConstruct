// from server: 100% by auto
// roc 2009-12 0083b780  unit: CXTPToolBar::CControlButtonExpand  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b780
//
// 0083b780  83791002             cmp dword ptr [ecx + 0x10], 2
// 0083b784  720c                 jb 0x83b792
// 0083b786  83790405             cmp dword ptr [ecx + 4], 5
// 0083b78a  7206                 jb 0x83b792
// 0083b78c  b801000000           mov eax, 1
// 0083b791  c3                   ret 
// 0083b792  33c0                 xor eax, eax
// 0083b794  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsWin2KOrGreater@CXTPSystemVersion@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
