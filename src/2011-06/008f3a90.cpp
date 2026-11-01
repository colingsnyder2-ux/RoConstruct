// from server: 100% by auto
// roc 2011-06 008f3a90  unit: CXTCaptionPopupWnd  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f3a90
//
// 008f3a90  837c240401           cmp dword ptr [esp + 4], 1
// 008f3a95  750d                 jne 0x8f3aa4
// 008f3a97  8b01                 mov eax, dword ptr [ecx]
// 008f3a99  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 008f3a9f  ffd2                 call edx
// 008f3aa1  c20400               ret 4
// 008f3aa4  e8856bf1ff           call 0x80a62e
// 008f3aa9  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Controls\Static\XTPCaptionPopupWnd.cpp (function ?OnTimer@CXTPCaptionPopupWnd@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Static/XTPCaptionPopupWnd.cpp
