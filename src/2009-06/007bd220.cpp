// from server: 100% by auto
// roc 2009-06 007bd220  unit: CXTPRibbonBar  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bd220
//
// 007bd220  83791400             cmp dword ptr [ecx + 0x14], 0
// 007bd224  7513                 jne 0x7bd239
// 007bd226  8b09                 mov ecx, dword ptr [ecx]
// 007bd228  e82302f7ff           call 0x72d450
// 007bd22d  83b88800000000       cmp dword ptr [eax + 0x88], 0
// 007bd234  7503                 jne 0x7bd239
// 007bd236  33c0                 xor eax, eax
// 007bd238  c3                   ret 
// 007bd239  b801000000           mov eax, 1
// 007bd23e  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?IsAnimationEnabled@CXTPCommandBarAnimation@@IBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
