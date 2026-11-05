// from server: 100% by auto
// roc 2010-06 008a88f0  unit: CXTCaptionButtonTheme  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a88f0
//
// 008a88f0  8b442404             mov eax, dword ptr [esp + 4]
// 008a88f4  85c0                 test eax, eax
// 008a88f6  7409                 je 0x8a8901
// 008a88f8  83780400             cmp dword ptr [eax + 4], 0
// 008a88fc  7403                 je 0x8a8901
// 008a88fe  89411c               mov dword ptr [ecx + 0x1c], eax
// 008a8901  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?SetThemeFont@CXTButtonTheme@@UAEXPAVCFont@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
