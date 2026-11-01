// from server: 100% by auto
// roc 2009-12 0085a770  unit: CXTPStatusBarPane  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085a770
//
// 0085a770  8b442404             mov eax, dword ptr [esp + 4]
// 0085a774  8b5168               mov edx, dword ptr [ecx + 0x68]
// 0085a777  8910                 mov dword ptr [eax], edx
// 0085a779  8b516c               mov edx, dword ptr [ecx + 0x6c]
// 0085a77c  895004               mov dword ptr [eax + 4], edx
// 0085a77f  8b5170               mov edx, dword ptr [ecx + 0x70]
// 0085a782  8b4974               mov ecx, dword ptr [ecx + 0x74]
// 0085a785  895008               mov dword ptr [eax + 8], edx
// 0085a788  89480c               mov dword ptr [eax + 0xc], ecx
// 0085a78b  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarDayViewEvent.cpp (function ?GetLastClockRect@CXTPCalendarViewEvent@@UBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarDayViewEvent.cpp
