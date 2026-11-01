// from server: 100% by auto
// roc 2009-06 00747790  unit: VCXTPReportRow::?$CXTPSmartPtrInternalT  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00747790
//
// 00747790  56                   push esi
// 00747791  8bf1                 mov esi, ecx
// 00747793  8b4e04               mov ecx, dword ptr [esi + 4]
// 00747796  c706ec4b8f00         mov dword ptr [esi], 0x8f4bec
// 0074779c  85c9                 test ecx, ecx
// 0074779e  7405                 je 0x7477a5
// 007477a0  e80318fdff           call 0x718fa8
// 007477a5  f644240801           test byte ptr [esp + 8], 1
// 007477aa  7409                 je 0x7477b5
// 007477ac  56                   push esi
// 007477ad  e88012fdff           call 0x718a32
// 007477b2  83c404               add esp, 4
// 007477b5  8bc6                 mov eax, esi
// 007477b7  5e                   pop esi
// 007477b8  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??_G?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
