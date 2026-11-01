// from server: 100% by auto
// roc 2007-08 00716100  unit: CXTCaptionPopupWnd  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00716100
//
// 00716100  837c240401           cmp dword ptr [esp + 4], 1
// 00716105  750d                 jne 0x716114
// 00716107  8b01                 mov eax, dword ptr [ecx]
// 00716109  8b9048010000         mov edx, dword ptr [eax + 0x148]
// 0071610f  ffd2                 call edx
// 00716111  c20400               ret 4
// 00716114  e825a1f1ff           call 0x63023e
// 00716119  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Static\XTPCaptionPopupWnd.cpp (function ?OnTimer@CXTPCaptionPopupWnd@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Static/XTPCaptionPopupWnd.cpp
