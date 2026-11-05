// from server: 100% by auto
// roc 2010-06 007d7510  unit: CXTPReportControl  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d7510
//
// 007d7510  83ec14               sub esp, 0x14
// 007d7513  33c0                 xor eax, eax
// 007d7515  8944240c             mov dword ptr [esp + 0xc], eax
// 007d7519  89442410             mov dword ptr [esp + 0x10], eax
// 007d751d  8d542418             lea edx, [esp + 0x18]
// 007d7521  890424               mov dword ptr [esp], eax
// 007d7524  89442404             mov dword ptr [esp + 4], eax
// 007d7528  89442408             mov dword ptr [esp + 8], eax
// 007d752c  8b442418             mov eax, dword ptr [esp + 0x18]
// 007d7530  8954240c             mov dword ptr [esp + 0xc], edx
// 007d7534  8d1424               lea edx, [esp]
// 007d7537  89442418             mov dword ptr [esp + 0x18], eax
// 007d753b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007d753f  52                   push edx
// 007d7540  6ac1                 push -0x3f
// 007d7542  89442418             mov dword ptr [esp + 0x18], eax
// 007d7546  e885fdffff           call 0x7d72d0
// 007d754b  f7d8                 neg eax
// 007d754d  1bc0                 sbb eax, eax
// 007d754f  f7d8                 neg eax
// 007d7551  83c414               add esp, 0x14
// 007d7554  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforeCopyToText@CXTPReportControl@@MAEHPAVCXTPReportRecord@@AAVCStringArray@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
