// from server: 100% by auto
// roc 2009-12 00823580  unit: CXTPReportControl  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823580
//
// 00823580  83ec28               sub esp, 0x28
// 00823583  8b542434             mov edx, dword ptr [esp + 0x34]
// 00823587  33c0                 xor eax, eax
// 00823589  8944240c             mov dword ptr [esp + 0xc], eax
// 0082358d  89442410             mov dword ptr [esp + 0x10], eax
// 00823591  89442414             mov dword ptr [esp + 0x14], eax
// 00823595  89442424             mov dword ptr [esp + 0x24], eax
// 00823599  890424               mov dword ptr [esp], eax
// 0082359c  89442404             mov dword ptr [esp + 4], eax
// 008235a0  89442408             mov dword ptr [esp + 8], eax
// 008235a4  89442418             mov dword ptr [esp + 0x18], eax
// 008235a8  8944241c             mov dword ptr [esp + 0x1c], eax
// 008235ac  89442420             mov dword ptr [esp + 0x20], eax
// 008235b0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008235b4  8944240c             mov dword ptr [esp + 0xc], eax
// 008235b8  8b442430             mov eax, dword ptr [esp + 0x30]
// 008235bc  89442410             mov dword ptr [esp + 0x10], eax
// 008235c0  8d0424               lea eax, [esp]
// 008235c3  89542414             mov dword ptr [esp + 0x14], edx
// 008235c7  8b542438             mov edx, dword ptr [esp + 0x38]
// 008235cb  50                   push eax
// 008235cc  6ab7                 push -0x49
// 008235ce  8954242c             mov dword ptr [esp + 0x2c], edx
// 008235d2  e899fcffff           call 0x823270
// 008235d7  f7d8                 neg eax
// 008235d9  1bc0                 sbb eax, eax
// 008235db  f7d8                 neg eax
// 008235dd  83c428               add esp, 0x28
// 008235e0  c21000               ret 0x10
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnConstraintSelecting@CXTPReportControl@@MAEHPAVCXTPReportRow@@PAVCXTPReportRecordItem@@PAVCXTPReportColumn@@PAVCXTPReportRecordItemConstraint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
