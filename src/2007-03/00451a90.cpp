// from server: 100% by auto
// roc 2007-03 00451a90  unit: seg_00450000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00451a90
//
// 00451a90  56                   push esi
// 00451a91  8bf1                 mov esi, ecx
// 00451a93  e848ffffff           call 0x4519e0
// 00451a98  8bce                 mov ecx, esi
// 00451a9a  e833cc1c00           call 0x61e6d2
// 00451a9f  5e                   pop esi
// 00451aa0  c20400               ret 4
// library xtp-15.2.1/Source\SyntaxEdit\XTPSyntaxEditColorSampleText.cpp (function ?OnEnable@CXTPSyntaxEditColorSampleText@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SyntaxEdit/XTPSyntaxEditColorSampleText.cpp
