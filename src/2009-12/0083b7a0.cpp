// from server: 100% by auto
// roc 2009-12 0083b7a0  unit: CXTPToolBar::CControlButtonExpand  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b7a0
//
// 0083b7a0  8b4104               mov eax, dword ptr [ecx + 4]
// 0083b7a3  8b542404             mov edx, dword ptr [esp + 4]
// 0083b7a7  3bc2                 cmp eax, edx
// 0083b7a9  7710                 ja 0x83b7bb
// 0083b7ab  7509                 jne 0x83b7b6
// 0083b7ad  8b4108               mov eax, dword ptr [ecx + 8]
// 0083b7b0  3b442408             cmp eax, dword ptr [esp + 8]
// 0083b7b4  7305                 jae 0x83b7bb
// 0083b7b6  33c0                 xor eax, eax
// 0083b7b8  c20800               ret 8
// 0083b7bb  b801000000           mov eax, 1
// 0083b7c0  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GreaterThanEqualTo@CXTPSystemVersion@@ABE_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
