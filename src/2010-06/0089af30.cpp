// from server: 100% by auto
// roc 2010-06 0089af30  unit: CXTCaptionPopupWnd  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089af30
//
// 0089af30  837c240401           cmp dword ptr [esp + 4], 1
// 0089af35  750d                 jne 0x89af44
// 0089af37  8b01                 mov eax, dword ptr [ecx]
// 0089af39  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 0089af3f  ffd2                 call edx
// 0089af41  c20400               ret 4
// 0089af44  e827d0f0ff           call 0x7a7f70
// 0089af49  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Controls\XTCaptionPopupWnd.cpp (function ?OnTimer@CXTCaptionPopupWnd@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTCaptionPopupWnd.cpp
