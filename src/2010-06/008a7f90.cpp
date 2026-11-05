// from server: 100% by auto
// roc 2010-06 008a7f90  unit: CXTMemDC  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a7f90
//
// 008a7f90  8b01                 mov eax, dword ptr [ecx]
// 008a7f92  8b4904               mov ecx, dword ptr [ecx + 4]
// 008a7f95  50                   push eax
// 008a7f96  e8194e0d00           call 0x97cdb4
// 008a7f9b  c3                   ret 
// library xtp-13.2.1/Source\Controls\XTButtonTheme.cpp (function ??1CXTContextBkModeHandler@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButtonTheme.cpp
