// from server: 100% by auto
// roc 2007-03 00685d90  unit: seg_00680000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00685d90
//
// 00685d90  8b4104               mov eax, dword ptr [ecx + 4]
// 00685d93  8b542404             mov edx, dword ptr [esp + 4]
// 00685d97  3bc2                 cmp eax, edx
// 00685d99  7710                 ja 0x685dab
// 00685d9b  7509                 jne 0x685da6
// 00685d9d  8b4108               mov eax, dword ptr [ecx + 8]
// 00685da0  3b442408             cmp eax, dword ptr [esp + 8]
// 00685da4  7305                 jae 0x685dab
// 00685da6  33c0                 xor eax, eax
// 00685da8  c20800               ret 8
// 00685dab  b801000000           mov eax, 1
// 00685db0  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GreaterThanEqualTo@CXTPSystemVersion@@ABE_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
