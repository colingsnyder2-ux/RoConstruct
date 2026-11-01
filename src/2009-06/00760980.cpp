// from server: 100% by auto
// roc 2009-06 00760980  unit: CXTPToolBar::CControlButtonExpand  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760980
//
// 00760980  b801000000           mov eax, 1
// 00760985  394110               cmp dword ptr [ecx + 0x10], eax
// 00760988  750c                 jne 0x760996
// 0076098a  83790404             cmp dword ptr [ecx + 4], 4
// 0076098e  7506                 jne 0x760996
// 00760990  8379080a             cmp dword ptr [ecx + 8], 0xa
// 00760994  7202                 jb 0x760998
// 00760996  33c0                 xor eax, eax
// 00760998  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsWin95@CXTPSystemVersion@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
