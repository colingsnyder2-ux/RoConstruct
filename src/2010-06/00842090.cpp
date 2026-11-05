// from server: 100% by auto
// roc 2010-06 00842090  unit: CXTPCommandBarAnimation::PAUCAnimateInfo::?$CArray  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00842090
//
// 00842090  56                   push esi
// 00842091  8bf1                 mov esi, ecx
// 00842093  8d4e04               lea ecx, [esi + 4]
// 00842096  e8c35ef6ff           call 0x7a7f5e
// 0084209b  8bce                 mov ecx, esi
// 0084209d  5e                   pop esi
// 0084209e  e96dffffff           jmp 0x842010
// library xtp-13.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?OnDestroy@CXTPCommandBarAnimation@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
