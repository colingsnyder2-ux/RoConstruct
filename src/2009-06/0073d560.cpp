// from server: 100% by auto
// roc 2009-06 0073d560  unit: CXTPReportViewPrintOptions  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073d560
//
// 0073d560  8b4904               mov ecx, dword ptr [ecx + 4]
// 0073d563  83ec08               sub esp, 8
// 0073d566  8d0424               lea eax, [esp]
// 0073d569  50                   push eax
// 0073d56a  51                   push ecx
// 0073d56b  ff1594e08900         call dword ptr [0x89e094]
// 0073d571  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0073d575  8b1424               mov edx, dword ptr [esp]
// 0073d578  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0073d57c  8910                 mov dword ptr [eax], edx
// 0073d57e  894804               mov dword ptr [eax + 4], ecx
// 0073d581  83c408               add esp, 8
// 0073d584  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarControlView.cpp (function ?GetBitmapDimension@CBitmap@@QBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarControlView.cpp
