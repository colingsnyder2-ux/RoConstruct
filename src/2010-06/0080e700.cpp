// from server: 100% by auto
// roc 2010-06 0080e700  unit: CXTPStatusBarPane  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080e700
//
// 0080e700  8b442404             mov eax, dword ptr [esp + 4]
// 0080e704  8b5168               mov edx, dword ptr [ecx + 0x68]
// 0080e707  8910                 mov dword ptr [eax], edx
// 0080e709  8b516c               mov edx, dword ptr [ecx + 0x6c]
// 0080e70c  895004               mov dword ptr [eax + 4], edx
// 0080e70f  8b5170               mov edx, dword ptr [ecx + 0x70]
// 0080e712  8b4974               mov ecx, dword ptr [ecx + 0x74]
// 0080e715  895008               mov dword ptr [eax + 8], edx
// 0080e718  89480c               mov dword ptr [eax + 0xc], ecx
// 0080e71b  c20400               ret 4
// library xtp-13.2.1/Source\Calendar\XTPCalendarDayViewEvent.cpp (function ?GetLastClockRect@CXTPCalendarViewEvent@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarDayViewEvent.cpp
