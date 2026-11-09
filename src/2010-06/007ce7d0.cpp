// from server: 100% by auto
// roc 2010-06 007ce7d0  unit: XTP_REPORTRECORDITEM_METRICS  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ce7d0
//
// 007ce7d0  56                   push esi
// 007ce7d1  8bf1                 mov esi, ecx
// 007ce7d3  8b4608               mov eax, dword ptr [esi + 8]
// 007ce7d6  57                   push edi
// 007ce7d7  8b3d80a39e00         mov edi, dword ptr [0x9ea380]
// 007ce7dd  85c0                 test eax, eax
// 007ce7df  7406                 je 0x7ce7e7
// 007ce7e1  83c004               add eax, 4
// 007ce7e4  50                   push eax
// 007ce7e5  ffd7                 call edi
// 007ce7e7  8b460c               mov eax, dword ptr [esi + 0xc]
// 007ce7ea  85c0                 test eax, eax
// 007ce7ec  7406                 je 0x7ce7f4
// 007ce7ee  83c004               add eax, 4
// 007ce7f1  50                   push eax
// 007ce7f2  ffd7                 call edi
// 007ce7f4  8b7610               mov esi, dword ptr [esi + 0x10]
// 007ce7f7  85f6                 test esi, esi
// 007ce7f9  7406                 je 0x7ce801
// 007ce7fb  83c604               add esi, 4
// 007ce7fe  56                   push esi
// 007ce7ff  ffd7                 call edi
// 007ce801  5f                   pop edi
// 007ce802  5e                   pop esi
// 007ce803  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportRecordItem.cpp (function ?AddRef@XTP_REPORTRECORDITEM_ARGS@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRecordItem.cpp
