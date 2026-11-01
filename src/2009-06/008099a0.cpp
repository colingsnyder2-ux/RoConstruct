// from server: 100% by auto
// roc 2009-06 008099a0  unit: CXTShadowWnd  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008099a0
//
// 008099a0  56                   push esi
// 008099a1  8bf1                 mov esi, ecx
// 008099a3  83bea000000000       cmp dword ptr [esi + 0xa0], 0
// 008099aa  750f                 jne 0x8099bb
// 008099ac  ff153cee8900         call dword ptr [0x89ee3c]
// 008099b2  3b4620               cmp eax, dword ptr [esi + 0x20]
// 008099b5  7404                 je 0x8099bb
// 008099b7  33c0                 xor eax, eax
// 008099b9  5e                   pop esi
// 008099ba  c3                   ret 
// 008099bb  b801000000           mov eax, 1
// 008099c0  5e                   pop esi
// 008099c1  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?GetHilite@CXTButton@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
