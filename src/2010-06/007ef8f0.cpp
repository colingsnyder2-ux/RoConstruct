// from server: 100% by auto
// roc 2010-06 007ef8f0  unit: CXTPToolBar::CControlButtonExpand  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ef8f0
//
// 007ef8f0  8b4104               mov eax, dword ptr [ecx + 4]
// 007ef8f3  8b542404             mov edx, dword ptr [esp + 4]
// 007ef8f7  3bc2                 cmp eax, edx
// 007ef8f9  7710                 ja 0x7ef90b
// 007ef8fb  7509                 jne 0x7ef906
// 007ef8fd  8b4108               mov eax, dword ptr [ecx + 8]
// 007ef900  3b442408             cmp eax, dword ptr [esp + 8]
// 007ef904  7305                 jae 0x7ef90b
// 007ef906  33c0                 xor eax, eax
// 007ef908  c20800               ret 8
// 007ef90b  b801000000           mov eax, 1
// 007ef910  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GreaterThanEqualTo@CXTPSystemVersion@@ABE_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
