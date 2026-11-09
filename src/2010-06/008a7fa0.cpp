// from server: 100% by auto
// roc 2010-06 008a7fa0  unit: CXTMemDC  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a7fa0
//
// 008a7fa0  8bc1                 mov eax, ecx
// 008a7fa2  8b4804               mov ecx, dword ptr [eax + 4]
// 008a7fa5  8b11                 mov edx, dword ptr [ecx]
// 008a7fa7  8b00                 mov eax, dword ptr [eax]
// 008a7fa9  8b5238               mov edx, dword ptr [edx + 0x38]
// 008a7fac  50                   push eax
// 008a7fad  ffd2                 call edx
// 008a7faf  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Controls\XTButtonTheme.cpp (function ??1CXTContextTextColorHandler@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTButtonTheme.cpp
