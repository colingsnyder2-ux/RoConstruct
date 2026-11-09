// from server: 100% by auto
// roc 2010-06 008213b0  unit: CXTCaption  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008213b0
//
// 008213b0  56                   push esi
// 008213b1  8bf1                 mov esi, ecx
// 008213b3  e8b86bf8ff           call 0x7a7f70
// 008213b8  83becc00000000       cmp dword ptr [esi + 0xcc], 0
// 008213bf  7413                 je 0x8213d4
// 008213c1  8b4620               mov eax, dword ptr [esi + 0x20]
// 008213c4  6805010000           push 0x105
// 008213c9  6a00                 push 0
// 008213cb  6a00                 push 0
// 008213cd  50                   push eax
// 008213ce  ff15d4b99e00         call dword ptr [0x9eb9d4]
// 008213d4  5e                   pop esi
// 008213d5  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?OnSize@CXTCaption@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp
