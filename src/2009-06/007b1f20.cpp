// from server: 100% by auto
// roc 2009-06 007b1f20  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b1f20
//
// 007b1f20  56                   push esi
// 007b1f21  8bf1                 mov esi, ecx
// 007b1f23  68f0b87100           push 0x71b8f0
// 007b1f28  b99426a500           mov ecx, 0xa52694
// 007b1f2d  e8ce9f0900           call 0x84bf00
// 007b1f32  85c0                 test eax, eax
// 007b1f34  7505                 jne 0x7b1f3b
// 007b1f36  e8a96df6ff           call 0x718ce4
// 007b1f3b  83780400             cmp dword ptr [eax + 4], 0
// 007b1f3f  7f08                 jg 0x7b1f49
// 007b1f41  8bce                 mov ecx, esi
// 007b1f43  5e                   pop esi
// 007b1f44  e977d7f6ff           jmp 0x71f6c0
// 007b1f49  5e                   pop esi
// 007b1f4a  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnMouseHover@CXTPControlEdit@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
