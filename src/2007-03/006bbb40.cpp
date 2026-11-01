// from server: 100% by auto
// roc 2007-03 006bbb40  unit: seg_006b0000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bbb40
//
// 006bbb40  8b442404             mov eax, dword ptr [esp + 4]
// 006bbb44  83f828               cmp eax, 0x28
// 006bbb47  740d                 je 0x6bbb56
// 006bbb49  83f826               cmp eax, 0x26
// 006bbb4c  7408                 je 0x6bbb56
// 006bbb4e  e87f2bf6ff           call 0x61e6d2
// 006bbb53  c20c00               ret 0xc
// 006bbb56  e865ffffff           call 0x6bbac0
// 006bbb5b  c20c00               ret 0xc
// library xtp-15.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?OnSysKeyDown@CXTPReportInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
