// from server: 100% by auto
// roc 2010-06 008937d0  unit: CXTColorPageCustom  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008937d0
//
// 008937d0  56                   push esi
// 008937d1  6a01                 push 1
// 008937d3  8bf1                 mov esi, ecx
// 008937d5  e84e44f1ff           call 0x7a7c28
// 008937da  0fb6866c070000       movzx eax, byte ptr [esi + 0x76c]
// 008937e1  0fb68e70070000       movzx ecx, byte ptr [esi + 0x770]
// 008937e8  0fb69668070000       movzx edx, byte ptr [esi + 0x768]
// 008937ef  c1e008               shl eax, 8
// 008937f2  0bc1                 or eax, ecx
// 008937f4  c1e008               shl eax, 8
// 008937f7  6a00                 push 0
// 008937f9  0bc2                 or eax, edx
// 008937fb  50                   push eax
// 008937fc  8bce                 mov ecx, esi
// 008937fe  e81dfaffff           call 0x893220
// 00893803  5e                   pop esi
// 00893804  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTColorPageCustom.cpp (function ?OnChangeEdit@CXTColorPageCustom@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageCustom.cpp
