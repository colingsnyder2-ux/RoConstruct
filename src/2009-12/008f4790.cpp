// from server: 100% by auto
// roc 2009-12 008f4790  unit: CXTCaptionButtonTheme  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f4790
//
// 008f4790  8b442404             mov eax, dword ptr [esp + 4]
// 008f4794  85c0                 test eax, eax
// 008f4796  7409                 je 0x8f47a1
// 008f4798  83780400             cmp dword ptr [eax + 4], 0
// 008f479c  7403                 je 0x8f47a1
// 008f479e  89411c               mov dword ptr [ecx + 0x1c], eax
// 008f47a1  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?SetThemeFont@CXTButtonTheme@@UAEXPAVCFont@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
