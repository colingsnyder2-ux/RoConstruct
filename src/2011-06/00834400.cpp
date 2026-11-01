// from server: 100% by auto
// roc 2011-06 00834400  unit: CXTPReportControl  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00834400
//
// 00834400  56                   push esi
// 00834401  8bf1                 mov esi, ecx
// 00834403  8b4620               mov eax, dword ptr [esi + 0x20]
// 00834406  57                   push edi
// 00834407  8b3db819a400         mov edi, dword ptr [0xa419b8]
// 0083440d  50                   push eax
// 0083440e  ffd7                 call edi
// 00834410  50                   push eax
// 00834411  e8125ffdff           call 0x80a328
// 00834416  50                   push eax
// 00834417  e83866fdff           call 0x80aa54
// 0083441c  50                   push eax
// 0083441d  e81a60fdff           call 0x80a43c
// 00834422  83c408               add esp, 8
// 00834425  85c0                 test eax, eax
// 00834427  741a                 je 0x834443
// 00834429  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0083442c  51                   push ecx
// 0083442d  ffd7                 call edi
// 0083442f  50                   push eax
// 00834430  e8f35efdff           call 0x80a328
// 00834435  8b10                 mov edx, dword ptr [eax]
// 00834437  5f                   pop edi
// 00834438  5e                   pop esi
// 00834439  8bc8                 mov ecx, eax
// 0083443b  8b9280000000         mov edx, dword ptr [edx + 0x80]
// 00834441  ffe2                 jmp edx
// 00834443  5f                   pop edi
// 00834444  33c0                 xor eax, eax
// 00834446  5e                   pop esi
// 00834447  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Calendar\XTPCalendarControl.cpp (function ?GetScrollBarCtrl@CXTPCalendarControl@@MBEPAVCScrollBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Calendar/XTPCalendarControl.cpp
