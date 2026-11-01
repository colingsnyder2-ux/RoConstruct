// from server: 100% by auto
// roc 2011-06 00833240  unit: XTP_REPORTRECORDITEM_METRICS  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00833240
//
// 00833240  53                   push ebx
// 00833241  56                   push esi
// 00833242  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00833246  57                   push edi
// 00833247  68e8dea700           push 0xa7dee8
// 0083324c  684ce5ab00           push 0xabe54c
// 00833251  8bce                 mov ecx, esi
// 00833253  ff15b828a400         call dword ptr [0xa428b8]
// 00833259  68004cac00           push 0xac4c00
// 0083325e  68fc4bac00           push 0xac4bfc
// 00833263  8bce                 mov ecx, esi
// 00833265  ff15b828a400         call dword ptr [0xa428b8]
// 0083326b  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0083326f  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00833273  57                   push edi
// 00833274  53                   push ebx
// 00833275  56                   push esi
// 00833276  e875d2ffff           call 0x8304f0
// 0083327b  57                   push edi
// 0083327c  53                   push ebx
// 0083327d  56                   push esi
// 0083327e  e80dd3ffff           call 0x830590
// 00833283  83c418               add esp, 0x18
// 00833286  5f                   pop edi
// 00833287  5e                   pop esi
// 00833288  5b                   pop ebx
// 00833289  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\ReportControl\XTPReportControlLocale.cpp (function ?_ProcessDateTimeSpecs@CXTPReportControlLocale@@CAXAAV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PBU_SYSTEMTIME@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/ReportControl/XTPReportControlLocale.cpp
