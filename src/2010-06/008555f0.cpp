// from server: 100% by auto
// roc 2010-06 008555f0  unit: CXTPReportInplaceList  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008555f0
//
// 008555f0  8b442404             mov eax, dword ptr [esp + 4]
// 008555f4  56                   push esi
// 008555f5  8bf1                 mov esi, ecx
// 008555f7  50                   push eax
// 008555f8  c7462c00000000       mov dword ptr [esi + 0x2c], 0
// 008555ff  e83cfeffff           call 0x855440
// 00855604  8d4e24               lea ecx, [esi + 0x24]
// 00855607  c7462800000000       mov dword ptr [esi + 0x28], 0
// 0085560e  ff1588c69e00         call dword ptr [0x9ec688]
// 00855614  5e                   pop esi
// 00855615  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\ReportControl\XTPReportInplaceControls.cpp (function ?SetItemArgs@CXTPReportInplaceList@@MAEXPAUXTP_REPORTRECORDITEM_ARGS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportInplaceControls.cpp
