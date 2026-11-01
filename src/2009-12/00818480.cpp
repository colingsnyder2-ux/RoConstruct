// from server: 100% by auto
// roc 2009-12 00818480  unit: CXTPReportViewPrintOptions  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00818480
//
// 00818480  8b4904               mov ecx, dword ptr [ecx + 4]
// 00818483  83ec08               sub esp, 8
// 00818486  8d0424               lea eax, [esp]
// 00818489  50                   push eax
// 0081848a  51                   push ecx
// 0081848b  ff15d8b09800         call dword ptr [0x98b0d8]
// 00818491  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00818495  8b1424               mov edx, dword ptr [esp]
// 00818498  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0081849c  8910                 mov dword ptr [eax], edx
// 0081849e  894804               mov dword ptr [eax + 4], ecx
// 008184a1  83c408               add esp, 8
// 008184a4  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarControlView.cpp (function ?GetBitmapDimension@CBitmap@@QBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarControlView.cpp
