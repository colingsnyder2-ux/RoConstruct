// from server: 100% by auto
// roc 2009-06 0073f750  unit: XTP_REPORTRECORDITEM_METRICS  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073f750
//
// 0073f750  33c0                 xor eax, eax
// 0073f752  56                   push esi
// 0073f753  8bf1                 mov esi, ecx
// 0073f755  894604               mov dword ptr [esi + 4], eax
// 0073f758  894608               mov dword ptr [esi + 8], eax
// 0073f75b  89460c               mov dword ptr [esi + 0xc], eax
// 0073f75e  894610               mov dword ptr [esi + 0x10], eax
// 0073f761  8d4614               lea eax, [esi + 0x14]
// 0073f764  50                   push eax
// 0073f765  c7062c438f00         mov dword ptr [esi], 0x8f432c
// 0073f76b  ff15c8ee8900         call dword ptr [0x89eec8]
// 0073f771  8bc6                 mov eax, esi
// 0073f773  5e                   pop esi
// 0073f774  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ??0XTP_REPORTRECORDITEM_ARGS@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
