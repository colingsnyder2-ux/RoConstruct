// from server: 100% by auto
// roc 2009-06 007609d0  unit: CXTPToolBar::CControlButtonExpand  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007609d0
//
// 007609d0  8b4104               mov eax, dword ptr [ecx + 4]
// 007609d3  8b542404             mov edx, dword ptr [esp + 4]
// 007609d7  3bc2                 cmp eax, edx
// 007609d9  7710                 ja 0x7609eb
// 007609db  7509                 jne 0x7609e6
// 007609dd  8b4108               mov eax, dword ptr [ecx + 8]
// 007609e0  3b442408             cmp eax, dword ptr [esp + 8]
// 007609e4  7305                 jae 0x7609eb
// 007609e6  33c0                 xor eax, eax
// 007609e8  c20800               ret 8
// 007609eb  b801000000           mov eax, 1
// 007609f0  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GreaterThanEqualTo@CXTPSystemVersion@@ABE_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
