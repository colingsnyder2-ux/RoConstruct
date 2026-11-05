// from server: 100% by auto
// roc 2010-06 00840490  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00840490
//
// 00840490  56                   push esi
// 00840491  8bf1                 mov esi, ecx
// 00840493  68e0a57a00           push 0x7aa5e0
// 00840498  b90062c200           mov ecx, 0xc26200
// 0084049d  e8d6c81300           call 0x97cd78
// 008404a2  85c0                 test eax, eax
// 008404a4  7505                 jne 0x8404ab
// 008404a6  e8a177f6ff           call 0x7a7c4c
// 008404ab  83780400             cmp dword ptr [eax + 4], 0
// 008404af  7f08                 jg 0x8404b9
// 008404b1  8bce                 mov ecx, esi
// 008404b3  5e                   pop esi
// 008404b4  e96799f6ff           jmp 0x7a9e20
// 008404b9  5e                   pop esi
// 008404ba  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnMouseHover@CXTPControlEdit@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlEdit.cpp
