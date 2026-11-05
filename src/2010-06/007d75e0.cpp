// from server: 100% by auto
// roc 2010-06 007d75e0  unit: CXTPReportControl  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d75e0
//
// 007d75e0  83ec28               sub esp, 0x28
// 007d75e3  8b542434             mov edx, dword ptr [esp + 0x34]
// 007d75e7  33c0                 xor eax, eax
// 007d75e9  8944240c             mov dword ptr [esp + 0xc], eax
// 007d75ed  89442410             mov dword ptr [esp + 0x10], eax
// 007d75f1  89442414             mov dword ptr [esp + 0x14], eax
// 007d75f5  89442424             mov dword ptr [esp + 0x24], eax
// 007d75f9  890424               mov dword ptr [esp], eax
// 007d75fc  89442404             mov dword ptr [esp + 4], eax
// 007d7600  89442408             mov dword ptr [esp + 8], eax
// 007d7604  89442418             mov dword ptr [esp + 0x18], eax
// 007d7608  8944241c             mov dword ptr [esp + 0x1c], eax
// 007d760c  89442420             mov dword ptr [esp + 0x20], eax
// 007d7610  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007d7614  8944240c             mov dword ptr [esp + 0xc], eax
// 007d7618  8b442430             mov eax, dword ptr [esp + 0x30]
// 007d761c  89442410             mov dword ptr [esp + 0x10], eax
// 007d7620  8d0424               lea eax, [esp]
// 007d7623  89542414             mov dword ptr [esp + 0x14], edx
// 007d7627  8b542438             mov edx, dword ptr [esp + 0x38]
// 007d762b  50                   push eax
// 007d762c  6ab7                 push -0x49
// 007d762e  8954242c             mov dword ptr [esp + 0x2c], edx
// 007d7632  e899fcffff           call 0x7d72d0
// 007d7637  f7d8                 neg eax
// 007d7639  1bc0                 sbb eax, eax
// 007d763b  f7d8                 neg eax
// 007d763d  83c428               add esp, 0x28
// 007d7640  c21000               ret 0x10
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnConstraintSelecting@CXTPReportControl@@MAEHPAVCXTPReportRow@@PAVCXTPReportRecordItem@@PAVCXTPReportColumn@@PAVCXTPReportRecordItemConstraint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
