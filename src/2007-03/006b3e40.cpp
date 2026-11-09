// from server: 100% by auto
// roc 2007-03 006b3e40  unit: seg_006b0000  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b3e40
//
// 006b3e40  83791400             cmp dword ptr [ecx + 0x14], 0
// 006b3e44  7513                 jne 0x6b3e59
// 006b3e46  8b09                 mov ecx, dword ptr [ecx]
// 006b3e48  e8834ff8ff           call 0x638dd0
// 006b3e4d  83b88400000000       cmp dword ptr [eax + 0x84], 0
// 006b3e54  7503                 jne 0x6b3e59
// 006b3e56  33c0                 xor eax, eax
// 006b3e58  c3                   ret 
// 006b3e59  b801000000           mov eax, 1
// 006b3e5e  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?IsAnimationEnabled@CXTPCommandBarAnimation@@IBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
