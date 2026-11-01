// from server: 100% by auto
// roc 2007-03 00721e50  unit: seg_00720000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00721e50
//
// 00721e50  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00721e53  83f8ff               cmp eax, -1
// 00721e56  7503                 jne 0x721e5b
// 00721e58  8b4124               mov eax, dword ptr [ecx + 0x24]
// 00721e5b  c3                   ret 
// library xtp-15.2.1/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?GetColorFace@CXTButtonTheme@@UAEKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButtonTheme.cpp
