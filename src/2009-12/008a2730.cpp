// from server: 100% by auto
// roc 2009-12 008a2730  unit: CXTPReportInplaceList  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a2730
//
// 008a2730  8b442404             mov eax, dword ptr [esp + 4]
// 008a2734  83f828               cmp eax, 0x28
// 008a2737  740d                 je 0x8a2746
// 008a2739  83f826               cmp eax, 0x26
// 008a273c  7408                 je 0x8a2746
// 008a273e  e8ed16f5ff           call 0x7f3e30
// 008a2743  c20c00               ret 0xc
// 008a2746  e8f5fdffff           call 0x8a2540
// 008a274b  c20c00               ret 0xc
// library xtp-15.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?OnSysKeyDown@CXTPReportInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
