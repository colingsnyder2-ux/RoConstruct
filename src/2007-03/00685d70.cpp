// from server: 100% by auto
// roc 2007-03 00685d70  unit: seg_00680000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00685d70
//
// 00685d70  83791002             cmp dword ptr [ecx + 0x10], 2
// 00685d74  720c                 jb 0x685d82
// 00685d76  83790405             cmp dword ptr [ecx + 4], 5
// 00685d7a  7206                 jb 0x685d82
// 00685d7c  b801000000           mov eax, 1
// 00685d81  c3                   ret 
// 00685d82  33c0                 xor eax, eax
// 00685d84  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsWin2KOrGreater@CXTPSystemVersion@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
