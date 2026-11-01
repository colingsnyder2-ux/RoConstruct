// from server: 100% by auto
// roc 2007-03 0067bbb0  unit: seg_00670000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067bbb0
//
// 0067bbb0  8b442404             mov eax, dword ptr [esp + 4]
// 0067bbb4  8b5168               mov edx, dword ptr [ecx + 0x68]
// 0067bbb7  8910                 mov dword ptr [eax], edx
// 0067bbb9  8b516c               mov edx, dword ptr [ecx + 0x6c]
// 0067bbbc  895004               mov dword ptr [eax + 4], edx
// 0067bbbf  8b5170               mov edx, dword ptr [ecx + 0x70]
// 0067bbc2  8b4974               mov ecx, dword ptr [ecx + 0x74]
// 0067bbc5  895008               mov dword ptr [eax + 8], edx
// 0067bbc8  89480c               mov dword ptr [eax + 0xc], ecx
// 0067bbcb  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarDayViewEvent.cpp (function ?GetLastClockRect@CXTPCalendarViewEvent@@UBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarDayViewEvent.cpp
