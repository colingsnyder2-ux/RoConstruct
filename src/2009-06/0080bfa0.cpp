// from server: 100% by auto
// roc 2009-06 0080bfa0  unit: CXTCaptionPopupWnd  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080bfa0
//
// 0080bfa0  56                   push esi
// 0080bfa1  8bf1                 mov esi, ecx
// 0080bfa3  8b4654               mov eax, dword ptr [esi + 0x54]
// 0080bfa6  85c0                 test eax, eax
// 0080bfa8  7403                 je 0x80bfad
// 0080bfaa  8b4020               mov eax, dword ptr [eax + 0x20]
// 0080bfad  50                   push eax
// 0080bfae  ff15e0ed8900         call dword ptr [0x89ede0]
// 0080bfb4  85c0                 test eax, eax
// 0080bfb6  7416                 je 0x80bfce
// 0080bfb8  8b4654               mov eax, dword ptr [esi + 0x54]
// 0080bfbb  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0080bfbe  6a00                 push 0
// 0080bfc0  6a00                 push 0
// 0080bfc2  683e270000           push 0x273e
// 0080bfc7  51                   push ecx
// 0080bfc8  ff1590ee8900         call dword ptr [0x89ee90]
// 0080bfce  5e                   pop esi
// 0080bfcf  c3                   ret 
// library xtp-15.2.1/Source\Controls\Static\XTPCaptionPopupWnd.cpp (function ?OnCaptButton@CXTPCaptionPopupWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Static/XTPCaptionPopupWnd.cpp
