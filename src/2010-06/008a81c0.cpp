// from server: 100% by auto
// roc 2010-06 008a81c0  unit: CXTCaptionButtonTheme  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a81c0
//
// 008a81c0  8b4128               mov eax, dword ptr [ecx + 0x28]
// 008a81c3  83f8ff               cmp eax, -1
// 008a81c6  7503                 jne 0x8a81cb
// 008a81c8  8b4124               mov eax, dword ptr [ecx + 0x24]
// 008a81cb  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ?GetColorFace@CXTButtonTheme@@UAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
