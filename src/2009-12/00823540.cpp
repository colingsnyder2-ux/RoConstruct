// from server: 100% by auto
// roc 2009-12 00823540  unit: CXTPReportControl  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823540
//
// 00823540  83ec14               sub esp, 0x14
// 00823543  33c0                 xor eax, eax
// 00823545  8d1424               lea edx, [esp]
// 00823548  8944240c             mov dword ptr [esp + 0xc], eax
// 0082354c  890424               mov dword ptr [esp], eax
// 0082354f  89442404             mov dword ptr [esp + 4], eax
// 00823553  89442408             mov dword ptr [esp + 8], eax
// 00823557  89442410             mov dword ptr [esp + 0x10], eax
// 0082355b  8b442418             mov eax, dword ptr [esp + 0x18]
// 0082355f  52                   push edx
// 00823560  6abf                 push -0x41
// 00823562  89442414             mov dword ptr [esp + 0x14], eax
// 00823566  e805fdffff           call 0x823270
// 0082356b  f7d8                 neg eax
// 0082356d  1bc0                 sbb eax, eax
// 0082356f  f7d8                 neg eax
// 00823571  83c414               add esp, 0x14
// 00823574  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforePaste@CXTPReportControl@@MAEHPAPAVCXTPReportRecord@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
