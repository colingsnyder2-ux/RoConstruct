// from server: 100% by auto
// roc 2011-06 00901680  unit: CXTMemDC  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00901680
//
// 00901680  8bc1                 mov eax, ecx
// 00901682  8b4804               mov ecx, dword ptr [eax + 4]
// 00901685  8b11                 mov edx, dword ptr [ecx]
// 00901687  8b00                 mov eax, dword ptr [eax]
// 00901689  8b5238               mov edx, dword ptr [edx + 0x38]
// 0090168c  50                   push eax
// 0090168d  ffd2                 call edx
// 0090168f  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Controls\Deprecated\XTButtonTheme.cpp (function ??1CXTPContextTextColorHandler@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Deprecated/XTButtonTheme.cpp
