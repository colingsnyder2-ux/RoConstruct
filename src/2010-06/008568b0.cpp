// from server: 100% by auto
// roc 2010-06 008568b0  unit: CXTPReportInplaceList  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008568b0
//
// 008568b0  8b442404             mov eax, dword ptr [esp + 4]
// 008568b4  83f828               cmp eax, 0x28
// 008568b7  740d                 je 0x8568c6
// 008568b9  83f826               cmp eax, 0x26
// 008568bc  7408                 je 0x8568c6
// 008568be  e8ad16f5ff           call 0x7a7f70
// 008568c3  c20c00               ret 0xc
// 008568c6  e8f5fdffff           call 0x8566c0
// 008568cb  c20c00               ret 0xc
// library xtp-13.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?OnSysKeyDown@CXTPReportInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
