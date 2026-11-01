// from server: 100% by auto
// roc 2010-06 007d30b0  unit: VCXTPReportRow::V?$CXTPSmartPtrInternalT::?$CArray  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d30b0
//
// 007d30b0  53                   push ebx
// 007d30b1  56                   push esi
// 007d30b2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007d30b6  57                   push edi
// 007d30b7  681492a500           push 0xa59214
// 007d30bc  683c36a500           push 0xa5363c
// 007d30c1  8bce                 mov ecx, esi
// 007d30c3  ff1514c89e00         call dword ptr [0x9ec814]
// 007d30c9  680c92a500           push 0xa5920c
// 007d30ce  680892a500           push 0xa59208
// 007d30d3  8bce                 mov ecx, esi
// 007d30d5  ff1514c89e00         call dword ptr [0x9ec814]
// 007d30db  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 007d30df  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 007d30e3  57                   push edi
// 007d30e4  53                   push ebx
// 007d30e5  56                   push esi
// 007d30e6  e8d5d2ffff           call 0x7d03c0
// 007d30eb  57                   push edi
// 007d30ec  53                   push ebx
// 007d30ed  56                   push esi
// 007d30ee  e86dd3ffff           call 0x7d0460
// 007d30f3  83c418               add esp, 0x18
// 007d30f6  5f                   pop edi
// 007d30f7  5e                   pop esi
// 007d30f8  5b                   pop ebx
// 007d30f9  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\ReportControl\XTPReportControl.cpp (function ?_ProcessDateTimeSpecs@CXTPReportControlLocale@@CAXAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PBU_SYSTEMTIME@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportControl.cpp
