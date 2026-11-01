// from server: 100% by auto
// roc 2007-08 00719a40  unit: CXTPRibbonSystemPopupBar  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00719a40
//
// 00719a40  8b442404             mov eax, dword ptr [esp + 4]
// 00719a44  8b91ec010000         mov edx, dword ptr [ecx + 0x1ec]
// 00719a4a  8910                 mov dword ptr [eax], edx
// 00719a4c  8b91f0010000         mov edx, dword ptr [ecx + 0x1f0]
// 00719a52  895004               mov dword ptr [eax + 4], edx
// 00719a55  8b91f4010000         mov edx, dword ptr [ecx + 0x1f4]
// 00719a5b  8b89f8010000         mov ecx, dword ptr [ecx + 0x1f8]
// 00719a61  895008               mov dword ptr [eax + 8], edx
// 00719a64  89480c               mov dword ptr [eax + 0xc], ecx
// 00719a67  c20400               ret 4
// library xtp-13.2.1/Source\Calendar\XTPCalendarDayView.cpp (function ?GetDayHeaderRectangle@CXTPCalendarDayView@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarDayView.cpp
