// from server: 100% by auto
// roc 2011-06 008f3480  unit: CXTCaptionPopupWnd  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f3480
//
// 008f3480  56                   push esi
// 008f3481  8bf1                 mov esi, ecx
// 008f3483  8b06                 mov eax, dword ptr [esi]
// 008f3485  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 008f348b  ffd2                 call edx
// 008f348d  8bce                 mov ecx, esi
// 008f348f  5e                   pop esi
// 008f3490  e98b76f1ff           jmp 0x80ab20
// library xtp-15.2.1-shared-mfc/Source\Controls\Static\XTPCaptionPopupWnd.cpp (function ?OnDestroy@CXTPCaptionPopupWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Static/XTPCaptionPopupWnd.cpp
