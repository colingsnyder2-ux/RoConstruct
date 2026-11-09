// from server: 100% by auto
// roc 2010-06 007d4270  unit: CXTPReportControl  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d4270
//
// 007d4270  56                   push esi
// 007d4271  8bf1                 mov esi, ecx
// 007d4273  8b4620               mov eax, dword ptr [esi + 0x20]
// 007d4276  57                   push edi
// 007d4277  8b3d4cba9e00         mov edi, dword ptr [0x9eba4c]
// 007d427d  50                   push eax
// 007d427e  ffd7                 call edi
// 007d4280  50                   push eax
// 007d4281  e8e439fdff           call 0x7a7c6a
// 007d4286  50                   push eax
// 007d4287  e80441fdff           call 0x7a8390
// 007d428c  50                   push eax
// 007d428d  e8ec3afdff           call 0x7a7d7e
// 007d4292  83c408               add esp, 8
// 007d4295  85c0                 test eax, eax
// 007d4297  741a                 je 0x7d42b3
// 007d4299  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 007d429c  51                   push ecx
// 007d429d  ffd7                 call edi
// 007d429f  50                   push eax
// 007d42a0  e8c539fdff           call 0x7a7c6a
// 007d42a5  8b10                 mov edx, dword ptr [eax]
// 007d42a7  5f                   pop edi
// 007d42a8  5e                   pop esi
// 007d42a9  8bc8                 mov ecx, eax
// 007d42ab  8b9280000000         mov edx, dword ptr [edx + 0x80]
// 007d42b1  ffe2                 jmp edx
// 007d42b3  5f                   pop edi
// 007d42b4  33c0                 xor eax, eax
// 007d42b6  5e                   pop esi
// 007d42b7  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Calendar\XTPCalendarControl.cpp (function ?GetScrollBarCtrl@CXTPCalendarControl@@MBEPAVCScrollBar@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Calendar/XTPCalendarControl.cpp
