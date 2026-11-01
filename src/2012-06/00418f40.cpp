// from server: 100% by auto
// roc 2012-06 00418f40  unit: CBitmap  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00418f40
//
// 00418f40  e84f995600           call 0x982894
// 00418f45  85c0                 test eax, eax
// 00418f47  7409                 je 0x418f52
// 00418f49  8b10                 mov edx, dword ptr [eax]
// 00418f4b  8bc8                 mov ecx, eax
// 00418f4d  8b427c               mov eax, dword ptr [edx + 0x7c]
// 00418f50  ffe0                 jmp eax
// 00418f52  33c0                 xor eax, eax
// 00418f54  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPDatePickerControl.cpp (function ?AfxGetMainWnd@@YGPAVCWnd@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPDatePickerControl.cpp
