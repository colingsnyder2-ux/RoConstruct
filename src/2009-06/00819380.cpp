// from server: 100% by auto
// roc 2009-06 00819380  unit: CXTCaptionButtonTheme  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00819380
//
// 00819380  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00819383  83f8ff               cmp eax, -1
// 00819386  7503                 jne 0x81938b
// 00819388  8b4124               mov eax, dword ptr [ecx + 0x24]
// 0081938b  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?GetColorFace@CXTButtonTheme@@UAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
