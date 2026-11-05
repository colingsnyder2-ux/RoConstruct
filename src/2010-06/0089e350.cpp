// from server: 100% by auto
// roc 2010-06 0089e350  unit: CXTPRibbonGroupControlPopup  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089e350
//
// 0089e350  83797000             cmp dword ptr [ecx + 0x70], 0
// 0089e354  750c                 jne 0x89e362
// 0089e356  83797400             cmp dword ptr [ecx + 0x74], 0
// 0089e35a  7406                 je 0x89e362
// 0089e35c  b801000000           mov eax, 1
// 0089e361  c3                   ret 
// 0089e362  33c0                 xor eax, eax
// 0089e364  c3                   ret 
// library xtp-13.2.1/Source\Ribbon\XTPRibbonGroup.cpp (function ?IsOptionButtonVisible@CXTPRibbonGroup@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonGroup.cpp
