// from server: 100% by auto
// roc 2009-12 008e5d30  unit: CXTCaptionButton  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5d30
//
// 008e5d30  56                   push esi
// 008e5d31  8bf1                 mov esi, ecx
// 008e5d33  83bea800000000       cmp dword ptr [esi + 0xa8], 0
// 008e5d3a  741c                 je 0x8e5d58
// 008e5d3c  ff15eccb9800         call dword ptr [0x98cbec]
// 008e5d42  50                   push eax
// 008e5d43  e8e2ddf0ff           call 0x7f3b2a
// 008e5d48  2bc6                 sub eax, esi
// 008e5d4a  f7d8                 neg eax
// 008e5d4c  1bc0                 sbb eax, eax
// 008e5d4e  83e0f0               and eax, 0xfffffff0
// 008e5d51  0510200000           add eax, 0x2010
// 008e5d56  5e                   pop esi
// 008e5d57  c3                   ret 
// 008e5d58  5e                   pop esi
// 008e5d59  e9d2e0f0ff           jmp 0x7f3e30
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnGetDlgCode@CXTButton@@IAEIXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
