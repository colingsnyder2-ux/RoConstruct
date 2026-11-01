// from server: 100% by auto
// roc 2009-06 00760b00  unit: CXTPToolBar::CControlButtonExpand  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760b00
//
// 00760b00  56                   push esi
// 00760b01  8bf1                 mov esi, ecx
// 00760b03  837e1000             cmp dword ptr [esi + 0x10], 0
// 00760b07  7505                 jne 0x760b0e
// 00760b09  e8b2ffffff           call 0x760ac0
// 00760b0e  0fb74614             movzx eax, word ptr [esi + 0x14]
// 00760b12  0fb74e18             movzx ecx, word ptr [esi + 0x18]
// 00760b16  c1e010               shl eax, 0x10
// 00760b19  0bc1                 or eax, ecx
// 00760b1b  5e                   pop esi
// 00760b1c  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetVersion@CXTPModuleHandle@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
