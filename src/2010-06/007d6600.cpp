// from server: 100% by auto
// roc 2010-06 007d6600  unit: VCXTPReportRow::?$CXTPSmartPtrInternalT  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d6600
//
// 007d6600  56                   push esi
// 007d6601  8bf1                 mov esi, ecx
// 007d6603  8b4e04               mov ecx, dword ptr [esi + 4]
// 007d6606  c7068493a500         mov dword ptr [esi], 0xa59384
// 007d660c  85c9                 test ecx, ecx
// 007d660e  7405                 je 0x7d6615
// 007d6610  e80719fdff           call 0x7a7f1c
// 007d6615  f644240801           test byte ptr [esp + 8], 1
// 007d661a  7409                 je 0x7d6625
// 007d661c  56                   push esi
// 007d661d  e87813fdff           call 0x7a799a
// 007d6622  83c404               add esp, 4
// 007d6625  8bc6                 mov eax, esi
// 007d6627  5e                   pop esi
// 007d6628  c20400               ret 4
// library xtp-13.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??_G?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
