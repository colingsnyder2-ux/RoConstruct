// from server: 100% by auto
// roc 2010-06 007d7560  unit: CXTPReportControl  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d7560
//
// 007d7560  83ec14               sub esp, 0x14
// 007d7563  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007d7567  33c0                 xor eax, eax
// 007d7569  8944240c             mov dword ptr [esp + 0xc], eax
// 007d756d  89442410             mov dword ptr [esp + 0x10], eax
// 007d7571  890424               mov dword ptr [esp], eax
// 007d7574  89442404             mov dword ptr [esp + 4], eax
// 007d7578  89442408             mov dword ptr [esp + 8], eax
// 007d757c  8b442418             mov eax, dword ptr [esp + 0x18]
// 007d7580  89442410             mov dword ptr [esp + 0x10], eax
// 007d7584  8d0424               lea eax, [esp]
// 007d7587  50                   push eax
// 007d7588  6ac0                 push -0x40
// 007d758a  89542414             mov dword ptr [esp + 0x14], edx
// 007d758e  e83dfdffff           call 0x7d72d0
// 007d7593  f7d8                 neg eax
// 007d7595  1bc0                 sbb eax, eax
// 007d7597  f7d8                 neg eax
// 007d7599  83c414               add esp, 0x14
// 007d759c  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforePasteFromText@CXTPReportControl@@MAEHAAVCStringArray@@PAPAVCXTPReportRecord@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
