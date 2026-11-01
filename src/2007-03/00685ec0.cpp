// from server: 100% by auto
// roc 2007-03 00685ec0  unit: seg_00680000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00685ec0
//
// 00685ec0  56                   push esi
// 00685ec1  8bf1                 mov esi, ecx
// 00685ec3  837e1000             cmp dword ptr [esi + 0x10], 0
// 00685ec7  7505                 jne 0x685ece
// 00685ec9  e8b2ffffff           call 0x685e80
// 00685ece  0fb74614             movzx eax, word ptr [esi + 0x14]
// 00685ed2  0fb74e18             movzx ecx, word ptr [esi + 0x18]
// 00685ed6  c1e010               shl eax, 0x10
// 00685ed9  0bc1                 or eax, ecx
// 00685edb  5e                   pop esi
// 00685edc  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetVersion@CXTPModuleHandle@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
