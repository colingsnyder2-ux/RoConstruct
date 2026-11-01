// from server: 100% by auto
// roc 2007-03 00648f80  unit: seg_00640000  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00648f80
//
// 00648f80  83ec14               sub esp, 0x14
// 00648f83  33c0                 xor eax, eax
// 00648f85  8944240c             mov dword ptr [esp + 0xc], eax
// 00648f89  89442410             mov dword ptr [esp + 0x10], eax
// 00648f8d  8d542418             lea edx, [esp + 0x18]
// 00648f91  890424               mov dword ptr [esp], eax
// 00648f94  89442404             mov dword ptr [esp + 4], eax
// 00648f98  89442408             mov dword ptr [esp + 8], eax
// 00648f9c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00648fa0  8954240c             mov dword ptr [esp + 0xc], edx
// 00648fa4  8d1424               lea edx, [esp]
// 00648fa7  89442418             mov dword ptr [esp + 0x18], eax
// 00648fab  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00648faf  52                   push edx
// 00648fb0  6ac1                 push -0x3f
// 00648fb2  89442418             mov dword ptr [esp + 0x18], eax
// 00648fb6  e8f5fcffff           call 0x648cb0
// 00648fbb  f7d8                 neg eax
// 00648fbd  1bc0                 sbb eax, eax
// 00648fbf  f7d8                 neg eax
// 00648fc1  83c414               add esp, 0x14
// 00648fc4  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforeCopyToText@CXTPReportControl@@MAEHPAVCXTPReportRecord@@AAVCStringArray@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
