// from server: 100% by auto
// roc 2009-12 008234b0  unit: CXTPReportControl  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008234b0
//
// 008234b0  83ec14               sub esp, 0x14
// 008234b3  33c0                 xor eax, eax
// 008234b5  8944240c             mov dword ptr [esp + 0xc], eax
// 008234b9  89442410             mov dword ptr [esp + 0x10], eax
// 008234bd  8d542418             lea edx, [esp + 0x18]
// 008234c1  890424               mov dword ptr [esp], eax
// 008234c4  89442404             mov dword ptr [esp + 4], eax
// 008234c8  89442408             mov dword ptr [esp + 8], eax
// 008234cc  8b442418             mov eax, dword ptr [esp + 0x18]
// 008234d0  8954240c             mov dword ptr [esp + 0xc], edx
// 008234d4  8d1424               lea edx, [esp]
// 008234d7  89442418             mov dword ptr [esp + 0x18], eax
// 008234db  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008234df  52                   push edx
// 008234e0  6ac1                 push -0x3f
// 008234e2  89442418             mov dword ptr [esp + 0x18], eax
// 008234e6  e885fdffff           call 0x823270
// 008234eb  f7d8                 neg eax
// 008234ed  1bc0                 sbb eax, eax
// 008234ef  f7d8                 neg eax
// 008234f1  83c414               add esp, 0x14
// 008234f4  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforeCopyToText@CXTPReportControl@@MAEHPAVCXTPReportRecord@@AAVCStringArray@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
