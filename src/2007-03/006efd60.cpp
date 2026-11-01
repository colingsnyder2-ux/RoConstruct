// from server: 100% by auto
// roc 2007-03 006efd60  unit: seg_006e0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006efd60
//
// 006efd60  56                   push esi
// 006efd61  8bf1                 mov esi, ecx
// 006efd63  ff150ced7700         call dword ptr [0x77ed0c]
// 006efd69  8bce                 mov ecx, esi
// 006efd6b  e862e9f2ff           call 0x61e6d2
// 006efd70  5e                   pop esi
// 006efd71  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnLButtonUp@CXTPColorBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
