// from server: 100% by auto
// roc 2009-12 0081a660  unit: XTP_REPORTRECORDITEM_METRICS  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081a660
//
// 0081a660  33c0                 xor eax, eax
// 0081a662  56                   push esi
// 0081a663  8bf1                 mov esi, ecx
// 0081a665  894604               mov dword ptr [esi + 4], eax
// 0081a668  894608               mov dword ptr [esi + 8], eax
// 0081a66b  89460c               mov dword ptr [esi + 0xc], eax
// 0081a66e  894610               mov dword ptr [esi + 0x10], eax
// 0081a671  8d4614               lea eax, [esi + 0x14]
// 0081a674  50                   push eax
// 0081a675  c706ec479f00         mov dword ptr [esi], 0x9f47ec
// 0081a67b  ff159cca9800         call dword ptr [0x98ca9c]
// 0081a681  8bc6                 mov eax, esi
// 0081a683  5e                   pop esi
// 0081a684  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ??0XTP_REPORTRECORDITEM_ARGS@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportRecordItem.cpp
