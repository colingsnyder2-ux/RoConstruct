// from server: 100% by auto
// roc 2009-12 008e5c40  unit: CXTCaptionButton  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e5c40
//
// 008e5c40  8b442408             mov eax, dword ptr [esp + 8]
// 008e5c44  56                   push esi
// 008e5c45  57                   push edi
// 008e5c46  8bf1                 mov esi, ecx
// 008e5c48  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008e5c4c  8b5620               mov edx, dword ptr [esi + 0x20]
// 008e5c4f  50                   push eax
// 008e5c50  51                   push ecx
// 008e5c51  6828010000           push 0x128
// 008e5c56  52                   push edx
// 008e5c57  ff15dcc99800         call dword ptr [0x98c9dc]
// 008e5c5d  6a00                 push 0
// 008e5c5f  8bf8                 mov edi, eax
// 008e5c61  8b4620               mov eax, dword ptr [esi + 0x20]
// 008e5c64  6a00                 push 0
// 008e5c66  50                   push eax
// 008e5c67  ff15e8cb9800         call dword ptr [0x98cbe8]
// 008e5c6d  8bc7                 mov eax, edi
// 008e5c6f  5f                   pop edi
// 008e5c70  5e                   pop esi
// 008e5c71  c20800               ret 8
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnUpdateUIState@CXTButton@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
