// from server: 100% by auto
// roc 2009-06 007609b0  unit: CXTPToolBar::CControlButtonExpand  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007609b0
//
// 007609b0  83791002             cmp dword ptr [ecx + 0x10], 2
// 007609b4  720c                 jb 0x7609c2
// 007609b6  83790405             cmp dword ptr [ecx + 4], 5
// 007609ba  7206                 jb 0x7609c2
// 007609bc  b801000000           mov eax, 1
// 007609c1  c3                   ret 
// 007609c2  33c0                 xor eax, eax
// 007609c4  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsWin2KOrGreater@CXTPSystemVersion@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
