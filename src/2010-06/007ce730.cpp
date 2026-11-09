// from server: 100% by auto
// roc 2010-06 007ce730  unit: XTP_REPORTRECORDITEM_METRICS  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ce730
//
// 007ce730  33c0                 xor eax, eax
// 007ce732  56                   push esi
// 007ce733  8bf1                 mov esi, ecx
// 007ce735  894604               mov dword ptr [esi + 4], eax
// 007ce738  894608               mov dword ptr [esi + 8], eax
// 007ce73b  89460c               mov dword ptr [esi + 0xc], eax
// 007ce73e  894610               mov dword ptr [esi + 0x10], eax
// 007ce741  8d4614               lea eax, [esi + 0x14]
// 007ce744  50                   push eax
// 007ce745  c706dc8aa500         mov dword ptr [esi], 0xa58adc
// 007ce74b  ff15e4ba9e00         call dword ptr [0x9ebae4]
// 007ce751  8bc6                 mov eax, esi
// 007ce753  5e                   pop esi
// 007ce754  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ??0XTP_REPORTRECORDITEM_ARGS@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRecordItem.cpp
