// from server: 100% by auto
// roc 2009-12 008f4070  unit: CXTCaptionButtonTheme  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f4070
//
// 008f4070  8b4128               mov eax, dword ptr [ecx + 0x28]
// 008f4073  83f8ff               cmp eax, -1
// 008f4076  7503                 jne 0x8f407b
// 008f4078  8b4124               mov eax, dword ptr [ecx + 0x24]
// 008f407b  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?GetColorFace@CXTButtonTheme@@UAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
