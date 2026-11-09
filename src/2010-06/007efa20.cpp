// from server: 100% by auto
// roc 2010-06 007efa20  unit: CXTPToolBar::CControlButtonExpand  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007efa20
//
// 007efa20  56                   push esi
// 007efa21  8bf1                 mov esi, ecx
// 007efa23  837e1000             cmp dword ptr [esi + 0x10], 0
// 007efa27  7505                 jne 0x7efa2e
// 007efa29  e8b2ffffff           call 0x7ef9e0
// 007efa2e  0fb74614             movzx eax, word ptr [esi + 0x14]
// 007efa32  0fb74e18             movzx ecx, word ptr [esi + 0x18]
// 007efa36  c1e010               shl eax, 0x10
// 007efa39  0bc1                 or eax, ecx
// 007efa3b  5e                   pop esi
// 007efa3c  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetVersion@CXTPModuleHandle@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
