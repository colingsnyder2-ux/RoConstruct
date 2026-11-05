// from server: 100% by auto
// roc 2010-06 007d75a0  unit: CXTPReportControl  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d75a0
//
// 007d75a0  83ec14               sub esp, 0x14
// 007d75a3  33c0                 xor eax, eax
// 007d75a5  8d1424               lea edx, [esp]
// 007d75a8  8944240c             mov dword ptr [esp + 0xc], eax
// 007d75ac  890424               mov dword ptr [esp], eax
// 007d75af  89442404             mov dword ptr [esp + 4], eax
// 007d75b3  89442408             mov dword ptr [esp + 8], eax
// 007d75b7  89442410             mov dword ptr [esp + 0x10], eax
// 007d75bb  8b442418             mov eax, dword ptr [esp + 0x18]
// 007d75bf  52                   push edx
// 007d75c0  6abf                 push -0x41
// 007d75c2  89442414             mov dword ptr [esp + 0x14], eax
// 007d75c6  e805fdffff           call 0x7d72d0
// 007d75cb  f7d8                 neg eax
// 007d75cd  1bc0                 sbb eax, eax
// 007d75cf  f7d8                 neg eax
// 007d75d1  83c414               add esp, 0x14
// 007d75d4  c20400               ret 4
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforePaste@CXTPReportControl@@MAEHPAPAVCXTPReportRecord@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
