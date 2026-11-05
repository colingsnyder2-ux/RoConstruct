// from server: 100% by auto
// roc 2007-03 007119d0  unit: seg_00710000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007119d0
//
// 007119d0  8b442404             mov eax, dword ptr [esp + 4]
// 007119d4  8b91ec010000         mov edx, dword ptr [ecx + 0x1ec]
// 007119da  8910                 mov dword ptr [eax], edx
// 007119dc  8b91f0010000         mov edx, dword ptr [ecx + 0x1f0]
// 007119e2  895004               mov dword ptr [eax + 4], edx
// 007119e5  8b91f4010000         mov edx, dword ptr [ecx + 0x1f4]
// 007119eb  8b89f8010000         mov ecx, dword ptr [ecx + 0x1f8]
// 007119f1  895008               mov dword ptr [eax + 8], edx
// 007119f4  89480c               mov dword ptr [eax + 0xc], ecx
// 007119f7  c20400               ret 4
// library xtp-13.2.1/Source\Calendar\XTPCalendarDayView.cpp (function ?GetDayHeaderRectangle@CXTPCalendarDayView@@UAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarDayView.cpp
