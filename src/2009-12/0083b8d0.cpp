// from server: 100% by auto
// roc 2009-12 0083b8d0  unit: CXTPToolBar::CControlButtonExpand  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b8d0
//
// 0083b8d0  56                   push esi
// 0083b8d1  8bf1                 mov esi, ecx
// 0083b8d3  837e1000             cmp dword ptr [esi + 0x10], 0
// 0083b8d7  7505                 jne 0x83b8de
// 0083b8d9  e8b2ffffff           call 0x83b890
// 0083b8de  0fb74614             movzx eax, word ptr [esi + 0x14]
// 0083b8e2  0fb74e18             movzx ecx, word ptr [esi + 0x18]
// 0083b8e6  c1e010               shl eax, 0x10
// 0083b8e9  0bc1                 or eax, ecx
// 0083b8eb  5e                   pop esi
// 0083b8ec  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetVersion@CXTPModuleHandle@@QAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
