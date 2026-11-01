// from server: 100% by auto
// roc 2009-06 0077f6b0  unit: CXTPStatusBarPane  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077f6b0
//
// 0077f6b0  8b442404             mov eax, dword ptr [esp + 4]
// 0077f6b4  8b5168               mov edx, dword ptr [ecx + 0x68]
// 0077f6b7  8910                 mov dword ptr [eax], edx
// 0077f6b9  8b516c               mov edx, dword ptr [ecx + 0x6c]
// 0077f6bc  895004               mov dword ptr [eax + 4], edx
// 0077f6bf  8b5170               mov edx, dword ptr [ecx + 0x70]
// 0077f6c2  8b4974               mov ecx, dword ptr [ecx + 0x74]
// 0077f6c5  895008               mov dword ptr [eax + 8], edx
// 0077f6c8  89480c               mov dword ptr [eax + 0xc], ecx
// 0077f6cb  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarDayViewEvent.cpp (function ?GetLastClockRect@CXTPCalendarViewEvent@@UBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarDayViewEvent.cpp
