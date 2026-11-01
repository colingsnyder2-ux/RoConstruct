// from server: 100% by auto
// roc 2011-06 00415980  unit: CBitmap  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00415980
//
// 00415980  e88f4e3f00           call 0x80a814
// 00415985  85c0                 test eax, eax
// 00415987  7409                 je 0x415992
// 00415989  8b10                 mov edx, dword ptr [eax]
// 0041598b  8bc8                 mov ecx, eax
// 0041598d  8b427c               mov eax, dword ptr [edx + 0x7c]
// 00415990  ffe0                 jmp eax
// 00415992  33c0                 xor eax, eax
// 00415994  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPDatePickerControl.cpp (function ?AfxGetMainWnd@@YGPAVCWnd@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPDatePickerControl.cpp
