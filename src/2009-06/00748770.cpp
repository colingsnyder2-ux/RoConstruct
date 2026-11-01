// from server: 100% by auto
// roc 2009-06 00748770  unit: CXTPReportControl  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748770
//
// 00748770  83ec28               sub esp, 0x28
// 00748773  8b542434             mov edx, dword ptr [esp + 0x34]
// 00748777  33c0                 xor eax, eax
// 00748779  8944240c             mov dword ptr [esp + 0xc], eax
// 0074877d  89442410             mov dword ptr [esp + 0x10], eax
// 00748781  89442414             mov dword ptr [esp + 0x14], eax
// 00748785  89442424             mov dword ptr [esp + 0x24], eax
// 00748789  890424               mov dword ptr [esp], eax
// 0074878c  89442404             mov dword ptr [esp + 4], eax
// 00748790  89442408             mov dword ptr [esp + 8], eax
// 00748794  89442418             mov dword ptr [esp + 0x18], eax
// 00748798  8944241c             mov dword ptr [esp + 0x1c], eax
// 0074879c  89442420             mov dword ptr [esp + 0x20], eax
// 007487a0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007487a4  8944240c             mov dword ptr [esp + 0xc], eax
// 007487a8  8b442430             mov eax, dword ptr [esp + 0x30]
// 007487ac  89442410             mov dword ptr [esp + 0x10], eax
// 007487b0  8d0424               lea eax, [esp]
// 007487b3  89542414             mov dword ptr [esp + 0x14], edx
// 007487b7  8b542438             mov edx, dword ptr [esp + 0x38]
// 007487bb  50                   push eax
// 007487bc  6ab7                 push -0x49
// 007487be  8954242c             mov dword ptr [esp + 0x2c], edx
// 007487c2  e899fcffff           call 0x748460
// 007487c7  f7d8                 neg eax
// 007487c9  1bc0                 sbb eax, eax
// 007487cb  f7d8                 neg eax
// 007487cd  83c428               add esp, 0x28
// 007487d0  c21000               ret 0x10
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?OnConstraintSelecting@CXTPReportControl@@MAEHPAVCXTPReportRow@@PAVCXTPReportRecordItem@@PAVCXTPReportColumn@@PAVCXTPReportRecordItemConstraint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
