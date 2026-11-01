// from server: 100% by auto
// roc 2009-06 007486a0  unit: CXTPReportControl  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007486a0
//
// 007486a0  83ec14               sub esp, 0x14
// 007486a3  33c0                 xor eax, eax
// 007486a5  8944240c             mov dword ptr [esp + 0xc], eax
// 007486a9  89442410             mov dword ptr [esp + 0x10], eax
// 007486ad  8d542418             lea edx, [esp + 0x18]
// 007486b1  890424               mov dword ptr [esp], eax
// 007486b4  89442404             mov dword ptr [esp + 4], eax
// 007486b8  89442408             mov dword ptr [esp + 8], eax
// 007486bc  8b442418             mov eax, dword ptr [esp + 0x18]
// 007486c0  8954240c             mov dword ptr [esp + 0xc], edx
// 007486c4  8d1424               lea edx, [esp]
// 007486c7  89442418             mov dword ptr [esp + 0x18], eax
// 007486cb  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007486cf  52                   push edx
// 007486d0  6ac1                 push -0x3f
// 007486d2  89442418             mov dword ptr [esp + 0x18], eax
// 007486d6  e885fdffff           call 0x748460
// 007486db  f7d8                 neg eax
// 007486dd  1bc0                 sbb eax, eax
// 007486df  f7d8                 neg eax
// 007486e1  83c414               add esp, 0x14
// 007486e4  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforeCopyToText@CXTPReportControl@@MAEHPAVCXTPReportRecord@@AAVCStringArray@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
