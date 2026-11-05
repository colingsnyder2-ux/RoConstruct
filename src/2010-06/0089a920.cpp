// from server: 100% by auto
// roc 2010-06 0089a920  unit: CXTCaptionPopupWnd  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089a920
//
// 0089a920  56                   push esi
// 0089a921  8bf1                 mov esi, ecx
// 0089a923  8b06                 mov eax, dword ptr [esi]
// 0089a925  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 0089a92b  ffd2                 call edx
// 0089a92d  8bce                 mov ecx, esi
// 0089a92f  5e                   pop esi
// 0089a930  e927dbf0ff           jmp 0x7a845c
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaptionPopupWnd.cpp (function ?OnDestroy@CXTCaptionPopupWnd@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaptionPopupWnd.cpp
