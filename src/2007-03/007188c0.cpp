// from server: 100% by auto
// roc 2007-03 007188c0  unit: seg_00710000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007188c0
//
// 007188c0  56                   push esi
// 007188c1  57                   push edi
// 007188c2  8bf1                 mov esi, ecx
// 007188c4  e8095ef0ff           call 0x61e6d2
// 007188c9  6a01                 push 1
// 007188cb  8bce                 mov ecx, esi
// 007188cd  8bf8                 mov edi, eax
// 007188cf  e8bc410000           call 0x71ca90
// 007188d4  6a00                 push 0
// 007188d6  8bce                 mov ecx, esi
// 007188d8  e8b3410000           call 0x71ca90
// 007188dd  8bc7                 mov eax, edi
// 007188df  5f                   pop edi
// 007188e0  5e                   pop esi
// 007188e1  c20800               ret 8
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectMDI.cpp (function ?OnCalcScroll@CXTPSkinObjectMDIClient@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectMDI.cpp
