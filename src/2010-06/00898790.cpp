// from server: 100% by auto
// roc 2010-06 00898790  unit: CXTShadowWnd  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00898790
//
// 00898790  56                   push esi
// 00898791  8bf1                 mov esi, ecx
// 00898793  83bea000000000       cmp dword ptr [esi + 0xa0], 0
// 0089879a  750f                 jne 0x8987ab
// 0089879c  ff1584bc9e00         call dword ptr [0x9ebc84]
// 008987a2  3b4620               cmp eax, dword ptr [esi + 0x20]
// 008987a5  7404                 je 0x8987ab
// 008987a7  33c0                 xor eax, eax
// 008987a9  5e                   pop esi
// 008987aa  c3                   ret 
// 008987ab  b801000000           mov eax, 1
// 008987b0  5e                   pop esi
// 008987b1  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?GetHilite@CXTButton@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
