// from server: 100% by auto
// roc 2007-03 00649010  unit: seg_00640000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00649010
//
// 00649010  83ec14               sub esp, 0x14
// 00649013  33c0                 xor eax, eax
// 00649015  8d1424               lea edx, [esp]
// 00649018  8944240c             mov dword ptr [esp + 0xc], eax
// 0064901c  890424               mov dword ptr [esp], eax
// 0064901f  89442404             mov dword ptr [esp + 4], eax
// 00649023  89442408             mov dword ptr [esp + 8], eax
// 00649027  89442410             mov dword ptr [esp + 0x10], eax
// 0064902b  8b442418             mov eax, dword ptr [esp + 0x18]
// 0064902f  52                   push edx
// 00649030  6abf                 push -0x41
// 00649032  89442414             mov dword ptr [esp + 0x14], eax
// 00649036  e875fcffff           call 0x648cb0
// 0064903b  f7d8                 neg eax
// 0064903d  1bc0                 sbb eax, eax
// 0064903f  f7d8                 neg eax
// 00649041  83c414               add esp, 0x14
// 00649044  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforePaste@CXTPReportControl@@MAEHPAPAVCXTPReportRecord@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
