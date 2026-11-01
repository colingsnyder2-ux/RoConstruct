// from server: 100% by auto
// roc 2009-12 008e9540  unit: CXTPRibbonGroupControlPopup  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e9540
//
// 008e9540  83797000             cmp dword ptr [ecx + 0x70], 0
// 008e9544  750c                 jne 0x8e9552
// 008e9546  83797400             cmp dword ptr [ecx + 0x74], 0
// 008e954a  7406                 je 0x8e9552
// 008e954c  b801000000           mov eax, 1
// 008e9551  c3                   ret 
// 008e9552  33c0                 xor eax, eax
// 008e9554  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroup.cpp (function ?IsOptionButtonVisible@CXTPRibbonGroup@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroup.cpp
