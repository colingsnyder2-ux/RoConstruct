// from server: 100% by auto
// roc 2009-12 008e6a90  unit: CXTCaptionPopupWnd  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e6a90
//
// 008e6a90  56                   push esi
// 008e6a91  8bf1                 mov esi, ecx
// 008e6a93  8b4654               mov eax, dword ptr [esi + 0x54]
// 008e6a96  85c0                 test eax, eax
// 008e6a98  7403                 je 0x8e6a9d
// 008e6a9a  8b4020               mov eax, dword ptr [eax + 0x20]
// 008e6a9d  50                   push eax
// 008e6a9e  ff1584cc9800         call dword ptr [0x98cc84]
// 008e6aa4  85c0                 test eax, eax
// 008e6aa6  7416                 je 0x8e6abe
// 008e6aa8  8b4654               mov eax, dword ptr [esi + 0x54]
// 008e6aab  8b4820               mov ecx, dword ptr [eax + 0x20]
// 008e6aae  6a00                 push 0
// 008e6ab0  6a00                 push 0
// 008e6ab2  683e270000           push 0x273e
// 008e6ab7  51                   push ecx
// 008e6ab8  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008e6abe  5e                   pop esi
// 008e6abf  c3                   ret 
// library xtp-15.2.1/Source\Controls\Static\XTPCaptionPopupWnd.cpp (function ?OnCaptButton@CXTPCaptionPopupWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Static/XTPCaptionPopupWnd.cpp
