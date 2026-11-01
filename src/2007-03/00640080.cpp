// from server: 100% by auto
// roc 2007-03 00640080  unit: seg_00640000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00640080
//
// 00640080  8b4904               mov ecx, dword ptr [ecx + 4]
// 00640083  83ec08               sub esp, 8
// 00640086  8d0424               lea eax, [esp]
// 00640089  50                   push eax
// 0064008a  51                   push ecx
// 0064008b  ff1538d17700         call dword ptr [0x77d138]
// 00640091  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00640095  8b1424               mov edx, dword ptr [esp]
// 00640098  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0064009c  8910                 mov dword ptr [eax], edx
// 0064009e  894804               mov dword ptr [eax + 4], ecx
// 006400a1  83c408               add esp, 8
// 006400a4  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarControlView.cpp (function ?GetBitmapDimension@CBitmap@@QBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarControlView.cpp
