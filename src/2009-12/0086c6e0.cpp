// from server: 100% by auto
// roc 2009-12 0086c6e0  unit: CXTCaption  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086c6e0
//
// 0086c6e0  56                   push esi
// 0086c6e1  8bf1                 mov esi, ecx
// 0086c6e3  e84877f8ff           call 0x7f3e30
// 0086c6e8  83becc00000000       cmp dword ptr [esi + 0xcc], 0
// 0086c6ef  7413                 je 0x86c704
// 0086c6f1  8b4620               mov eax, dword ptr [esi + 0x20]
// 0086c6f4  6805010000           push 0x105
// 0086c6f9  6a00                 push 0
// 0086c6fb  6a00                 push 0
// 0086c6fd  50                   push eax
// 0086c6fe  ff151ccb9800         call dword ptr [0x98cb1c]
// 0086c704  5e                   pop esi
// 0086c705  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaption.cpp (function ?OnSize@CXTCaption@@IAEXIHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaption.cpp
