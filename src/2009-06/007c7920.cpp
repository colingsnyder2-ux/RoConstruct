// from server: 100% by auto
// roc 2009-06 007c7920  unit: CXTPReportInplaceList  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c7920
//
// 007c7920  8b442404             mov eax, dword ptr [esp + 4]
// 007c7924  83f828               cmp eax, 0x28
// 007c7927  740d                 je 0x7c7936
// 007c7929  83f826               cmp eax, 0x26
// 007c792c  7408                 je 0x7c7936
// 007c792e  e8d516f5ff           call 0x719008
// 007c7933  c20c00               ret 0xc
// 007c7936  e8f5fdffff           call 0x7c7730
// 007c793b  c20c00               ret 0xc
// library xtp-15.2.1/Source\ReportControl\XTPReportInplaceControls.cpp (function ?OnSysKeyDown@CXTPReportInplaceList@@IAEXIII@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportInplaceControls.cpp
