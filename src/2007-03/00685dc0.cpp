// from server: 100% by auto
// roc 2007-03 00685dc0  unit: seg_00680000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00685dc0
//
// 00685dc0  8b4104               mov eax, dword ptr [ecx + 4]
// 00685dc3  3b442404             cmp eax, dword ptr [esp + 4]
// 00685dc7  7511                 jne 0x685dda
// 00685dc9  8b4908               mov ecx, dword ptr [ecx + 8]
// 00685dcc  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 00685dd0  7508                 jne 0x685dda
// 00685dd2  b801000000           mov eax, 1
// 00685dd7  c20800               ret 8
// 00685dda  33c0                 xor eax, eax
// 00685ddc  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?EqualTo@CXTPSystemVersion@@ABE_NKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
