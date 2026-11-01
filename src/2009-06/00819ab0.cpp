// from server: 100% by auto
// roc 2009-06 00819ab0  unit: CXTCaptionButtonTheme  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00819ab0
//
// 00819ab0  8b442404             mov eax, dword ptr [esp + 4]
// 00819ab4  85c0                 test eax, eax
// 00819ab6  7409                 je 0x819ac1
// 00819ab8  83780400             cmp dword ptr [eax + 4], 0
// 00819abc  7403                 je 0x819ac1
// 00819abe  89411c               mov dword ptr [ecx + 0x1c], eax
// 00819ac1  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?SetThemeFont@CXTButtonTheme@@UAEXPAVCFont@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
