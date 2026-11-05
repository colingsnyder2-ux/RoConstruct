// from server: 100% by auto
// roc 2010-06 0089e320  unit: CXTPRibbonGroupControlPopup  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089e320
//
// 0089e320  56                   push esi
// 0089e321  8bf1                 mov esi, ecx
// 0089e323  8b4658               mov eax, dword ptr [esi + 0x58]
// 0089e326  50                   push eax
// 0089e327  e884570000           call 0x8a3ab0
// 0089e32c  83c404               add esp, 4
// 0089e32f  85c0                 test eax, eax
// 0089e331  740c                 je 0x89e33f
// 0089e333  397014               cmp dword ptr [eax + 0x14], esi
// 0089e336  7507                 jne 0x89e33f
// 0089e338  b801000000           mov eax, 1
// 0089e33d  5e                   pop esi
// 0089e33e  c3                   ret 
// 0089e33f  33c0                 xor eax, eax
// 0089e341  5e                   pop esi
// 0089e342  c3                   ret 
// library xtp-13.2.1/Source\Ribbon\XTPRibbonGroup.cpp (function ?IsHighlighted@CXTPRibbonGroup@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonGroup.cpp
