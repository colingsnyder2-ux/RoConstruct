// from server: 100% by auto
// roc 2009-12 008df580  unit: CXTColorPageCustom  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008df580
//
// 008df580  56                   push esi
// 008df581  6a01                 push 1
// 008df583  8bf1                 mov esi, ecx
// 008df585  e85e45f1ff           call 0x7f3ae8
// 008df58a  0fb6866c070000       movzx eax, byte ptr [esi + 0x76c]
// 008df591  0fb68e70070000       movzx ecx, byte ptr [esi + 0x770]
// 008df598  0fb69668070000       movzx edx, byte ptr [esi + 0x768]
// 008df59f  c1e008               shl eax, 8
// 008df5a2  0bc1                 or eax, ecx
// 008df5a4  c1e008               shl eax, 8
// 008df5a7  6a00                 push 0
// 008df5a9  0bc2                 or eax, edx
// 008df5ab  50                   push eax
// 008df5ac  8bce                 mov ecx, esi
// 008df5ae  e81dfaffff           call 0x8defd0
// 008df5b3  5e                   pop esi
// 008df5b4  c3                   ret 
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorPageCustom.cpp (function ?OnChangeEdit@CXTPColorPageCustom@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorPageCustom.cpp
