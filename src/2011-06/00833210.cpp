// from server: 100% by auto
// roc 2011-06 00833210  unit: XTP_REPORTRECORDITEM_METRICS  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00833210
//
// 00833210  56                   push esi
// 00833211  8bf1                 mov esi, ecx
// 00833213  8d4e2c               lea ecx, [esi + 0x2c]
// 00833216  ff15082ea400         call dword ptr [0xa42e08]
// 0083321c  8bce                 mov ecx, esi
// 0083321e  e8c379fdff           call 0x80abe6
// 00833223  f644240801           test byte ptr [esp + 8], 1
// 00833228  7409                 je 0x833233
// 0083322a  56                   push esi
// 0083322b  e8286efdff           call 0x80a058
// 00833230  83c404               add esp, 4
// 00833233  8bc6                 mov eax, esi
// 00833235  5e                   pop esi
// 00833236  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\ReportControl\ItemTypes\XTPReportRecordItemPreview.cpp (function ??_GXTP_REPORTRECORDITEM_METRICS@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/ReportControl/ItemTypes/XTPReportRecordItemPreview.cpp
