// from server: 100% by auto
// roc 2009-12 0088cdd0  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088cdd0
//
// 0088cdd0  56                   push esi
// 0088cdd1  8bf1                 mov esi, ecx
// 0088cdd3  68b0647f00           push 0x7f64b0
// 0088cdd8  b9d0bab900           mov ecx, 0xb9bad0
// 0088cddd  e85a960900           call 0x92643c
// 0088cde2  85c0                 test eax, eax
// 0088cde4  7505                 jne 0x88cdeb
// 0088cde6  e8216df6ff           call 0x7f3b0c
// 0088cdeb  83780400             cmp dword ptr [eax + 4], 0
// 0088cdef  7f08                 jg 0x88cdf9
// 0088cdf1  8bce                 mov ecx, esi
// 0088cdf3  5e                   pop esi
// 0088cdf4  e9e78ef6ff           jmp 0x7f5ce0
// 0088cdf9  5e                   pop esi
// 0088cdfa  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnMouseHover@CXTPControlEdit@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
