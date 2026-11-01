// from server: 100% by auto
// roc 2009-12 008e9510  unit: CXTPRibbonGroupControlPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e9510
//
// 008e9510  56                   push esi
// 008e9511  8bf1                 mov esi, ecx
// 008e9513  8b4658               mov eax, dword ptr [esi + 0x58]
// 008e9516  50                   push eax
// 008e9517  e894630000           call 0x8ef8b0
// 008e951c  83c404               add esp, 4
// 008e951f  85c0                 test eax, eax
// 008e9521  740c                 je 0x8e952f
// 008e9523  397014               cmp dword ptr [eax + 0x14], esi
// 008e9526  7507                 jne 0x8e952f
// 008e9528  b801000000           mov eax, 1
// 008e952d  5e                   pop esi
// 008e952e  c3                   ret 
// 008e952f  33c0                 xor eax, eax
// 008e9531  5e                   pop esi
// 008e9532  c3                   ret 
// library xtp-15.2.1/Source\Ribbon\XTPRibbonGroup.cpp (function ?IsHighlighted@CXTPRibbonGroup@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonGroup.cpp
