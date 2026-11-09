// from server: 100% by auto
// roc 2010-06 0089adb0  unit: CXTCaptionPopupWnd  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089adb0
//
// 0089adb0  56                   push esi
// 0089adb1  8bf1                 mov esi, ecx
// 0089adb3  8b4654               mov eax, dword ptr [esi + 0x54]
// 0089adb6  85c0                 test eax, eax
// 0089adb8  7403                 je 0x89adbd
// 0089adba  8b4020               mov eax, dword ptr [eax + 0x20]
// 0089adbd  50                   push eax
// 0089adbe  ff1528bc9e00         call dword ptr [0x9ebc28]
// 0089adc4  85c0                 test eax, eax
// 0089adc6  7416                 je 0x89adde
// 0089adc8  8b4654               mov eax, dword ptr [esi + 0x54]
// 0089adcb  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0089adce  6a00                 push 0
// 0089add0  6a00                 push 0
// 0089add2  683e270000           push 0x273e
// 0089add7  51                   push ecx
// 0089add8  ff1554ba9e00         call dword ptr [0x9eba54]
// 0089adde  5e                   pop esi
// 0089addf  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTCaptionPopupWnd.cpp (function ?OnCaptButton@CXTCaptionPopupWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionPopupWnd.cpp
