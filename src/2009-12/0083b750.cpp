// from server: 100% by auto
// roc 2009-12 0083b750  unit: CXTPToolBar::CControlButtonExpand  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b750
//
// 0083b750  b801000000           mov eax, 1
// 0083b755  394110               cmp dword ptr [ecx + 0x10], eax
// 0083b758  750c                 jne 0x83b766
// 0083b75a  83790404             cmp dword ptr [ecx + 4], 4
// 0083b75e  7506                 jne 0x83b766
// 0083b760  8379080a             cmp dword ptr [ecx + 8], 0xa
// 0083b764  7202                 jb 0x83b768
// 0083b766  33c0                 xor eax, eax
// 0083b768  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsWin95@CXTPSystemVersion@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
