// from server: 100% by auto
// roc 2007-03 0070e500  unit: seg_00700000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0070e500
//
// 0070e500  83797000             cmp dword ptr [ecx + 0x70], 0
// 0070e504  750c                 jne 0x70e512
// 0070e506  83797400             cmp dword ptr [ecx + 0x74], 0
// 0070e50a  7406                 je 0x70e512
// 0070e50c  b801000000           mov eax, 1
// 0070e511  c3                   ret 
// 0070e512  33c0                 xor eax, eax
// 0070e514  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroup.cpp (function ?IsOptionButtonVisible@CXTPRibbonGroup@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroup.cpp
