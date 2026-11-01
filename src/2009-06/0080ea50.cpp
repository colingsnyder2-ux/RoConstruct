// from server: 100% by auto
// roc 2009-06 0080ea50  unit: CXTPRibbonGroupControlPopup  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080ea50
//
// 0080ea50  83797000             cmp dword ptr [ecx + 0x70], 0
// 0080ea54  750c                 jne 0x80ea62
// 0080ea56  83797400             cmp dword ptr [ecx + 0x74], 0
// 0080ea5a  7406                 je 0x80ea62
// 0080ea5c  b801000000           mov eax, 1
// 0080ea61  c3                   ret 
// 0080ea62  33c0                 xor eax, eax
// 0080ea64  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroup.cpp (function ?IsOptionButtonVisible@CXTPRibbonGroup@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroup.cpp
