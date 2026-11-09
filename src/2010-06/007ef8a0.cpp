// from server: 100% by auto
// roc 2010-06 007ef8a0  unit: CXTPToolBar::CControlButtonExpand  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ef8a0
//
// 007ef8a0  b801000000           mov eax, 1
// 007ef8a5  394110               cmp dword ptr [ecx + 0x10], eax
// 007ef8a8  750c                 jne 0x7ef8b6
// 007ef8aa  83790404             cmp dword ptr [ecx + 4], 4
// 007ef8ae  7506                 jne 0x7ef8b6
// 007ef8b0  8379080a             cmp dword ptr [ecx + 8], 0xa
// 007ef8b4  7202                 jb 0x7ef8b8
// 007ef8b6  33c0                 xor eax, eax
// 007ef8b8  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsWin95@CXTPSystemVersion@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
