// from server: 100% by auto
// roc 2010-06 007ce700  unit: XTP_REPORTRECORDITEM_METRICS  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ce700
//
// 007ce700  56                   push esi
// 007ce701  8bf1                 mov esi, ecx
// 007ce703  8d4e2c               lea ecx, [esi + 0x2c]
// 007ce706  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 007ce70c  8bce                 mov ecx, esi
// 007ce70e  e80f9efdff           call 0x7a8522
// 007ce713  f644240801           test byte ptr [esp + 8], 1
// 007ce718  7409                 je 0x7ce723
// 007ce71a  56                   push esi
// 007ce71b  e87a92fdff           call 0x7a799a
// 007ce720  83c404               add esp, 4
// 007ce723  8bc6                 mov eax, esi
// 007ce725  5e                   pop esi
// 007ce726  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\ReportControl\XTPReportControl.cpp (function ??_GXTP_REPORTRECORDITEM_METRICS@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportControl.cpp
