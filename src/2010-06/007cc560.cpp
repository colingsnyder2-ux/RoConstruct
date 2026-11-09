// from server: 100% by auto
// roc 2010-06 007cc560  unit: CXTPReportViewPrintOptions  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cc560
//
// 007cc560  8b4904               mov ecx, dword ptr [ecx + 4]
// 007cc563  83ec08               sub esp, 8
// 007cc566  8d0424               lea eax, [esp]
// 007cc569  50                   push eax
// 007cc56a  51                   push ecx
// 007cc56b  ff1520a19e00         call dword ptr [0x9ea120]
// 007cc571  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007cc575  8b1424               mov edx, dword ptr [esp]
// 007cc578  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007cc57c  8910                 mov dword ptr [eax], edx
// 007cc57e  894804               mov dword ptr [eax + 4], ecx
// 007cc581  83c408               add esp, 8
// 007cc584  c20400               ret 4
// library xtp-13.2.1/Source\Calendar\XTPCalendarControlView.cpp (function ?GetBitmapDimension@CBitmap@@QBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarControlView.cpp
