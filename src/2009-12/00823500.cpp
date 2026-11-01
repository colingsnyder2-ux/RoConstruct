// from server: 100% by auto
// roc 2009-12 00823500  unit: CXTPReportControl  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823500
//
// 00823500  83ec14               sub esp, 0x14
// 00823503  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00823507  33c0                 xor eax, eax
// 00823509  8944240c             mov dword ptr [esp + 0xc], eax
// 0082350d  89442410             mov dword ptr [esp + 0x10], eax
// 00823511  890424               mov dword ptr [esp], eax
// 00823514  89442404             mov dword ptr [esp + 4], eax
// 00823518  89442408             mov dword ptr [esp + 8], eax
// 0082351c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00823520  89442410             mov dword ptr [esp + 0x10], eax
// 00823524  8d0424               lea eax, [esp]
// 00823527  50                   push eax
// 00823528  6ac0                 push -0x40
// 0082352a  89542414             mov dword ptr [esp + 0x14], edx
// 0082352e  e83dfdffff           call 0x823270
// 00823533  f7d8                 neg eax
// 00823535  1bc0                 sbb eax, eax
// 00823537  f7d8                 neg eax
// 00823539  83c414               add esp, 0x14
// 0082353c  c20800               ret 8
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnBeforePasteFromText@CXTPReportControl@@MAEHAAVCStringArray@@PAPAVCXTPReportRecord@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
