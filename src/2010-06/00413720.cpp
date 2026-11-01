// from server: 100% by auto
// roc 2010-06 00413720  unit: CClassImages  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413720
//
// 00413720  e8314a3900           call 0x7a8156
// 00413725  85c0                 test eax, eax
// 00413727  7409                 je 0x413732
// 00413729  8b10                 mov edx, dword ptr [eax]
// 0041372b  8bc8                 mov ecx, eax
// 0041372d  8b427c               mov eax, dword ptr [edx + 0x7c]
// 00413730  ffe0                 jmp eax
// 00413732  33c0                 xor eax, eax
// 00413734  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Calendar\XTPDatePickerControl.cpp (function ?AfxGetMainWnd@@YGPAVCWnd@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Calendar/XTPDatePickerControl.cpp
