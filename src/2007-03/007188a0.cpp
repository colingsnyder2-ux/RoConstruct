// from server: 100% by auto
// roc 2007-03 007188a0  unit: seg_00710000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007188a0
//
// 007188a0  56                   push esi
// 007188a1  8bf1                 mov esi, ecx
// 007188a3  e82a5ef0ff           call 0x61e6d2
// 007188a8  6a01                 push 1
// 007188aa  8bce                 mov ecx, esi
// 007188ac  e8df410000           call 0x71ca90
// 007188b1  5e                   pop esi
// 007188b2  c20c00               ret 0xc
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectMDI.cpp (function ?OnVScroll@CXTPSkinObjectMDIClient@@IAEXIIPAVCScrollBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectMDI.cpp
