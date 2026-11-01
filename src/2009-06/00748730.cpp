// from server: 100% by auto
// roc 2009-06 00748730  unit: CXTPReportControl  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748730
//
// 00748730  83ec14               sub esp, 0x14
// 00748733  33c0                 xor eax, eax
// 00748735  8d1424               lea edx, [esp]
// 00748738  8944240c             mov dword ptr [esp + 0xc], eax
// 0074873c  890424               mov dword ptr [esp], eax
// 0074873f  89442404             mov dword ptr [esp + 4], eax
// 00748743  89442408             mov dword ptr [esp + 8], eax
// 00748747  89442410             mov dword ptr [esp + 0x10], eax
// 0074874b  8b442418             mov eax, dword ptr [esp + 0x18]
// 0074874f  52                   push edx
// 00748750  6abf                 push -0x41
// 00748752  89442414             mov dword ptr [esp + 0x14], eax
// 00748756  e805fdffff           call 0x748460
// 0074875b  f7d8                 neg eax
// 0074875d  1bc0                 sbb eax, eax
// 0074875f  f7d8                 neg eax
// 00748761  83c414               add esp, 0x14
// 00748764  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforePaste@CXTPReportControl@@MAEHPAPAVCXTPReportRecord@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
