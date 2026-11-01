// from server: 100% by auto
// roc 2007-03 00685d40  unit: seg_00680000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00685d40
//
// 00685d40  b801000000           mov eax, 1
// 00685d45  394110               cmp dword ptr [ecx + 0x10], eax
// 00685d48  750c                 jne 0x685d56
// 00685d4a  83790404             cmp dword ptr [ecx + 4], 4
// 00685d4e  7506                 jne 0x685d56
// 00685d50  8379080a             cmp dword ptr [ecx + 8], 0xa
// 00685d54  7202                 jb 0x685d58
// 00685d56  33c0                 xor eax, eax
// 00685d58  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?IsWin95@CXTPSystemVersion@@QBE_NXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
