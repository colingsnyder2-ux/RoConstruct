// from server: 100% by auto
// roc 2009-12 008225a0  unit: VCXTPReportRow::?$CXTPSmartPtrInternalT  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008225a0
//
// 008225a0  56                   push esi
// 008225a1  8bf1                 mov esi, ecx
// 008225a3  8b4e04               mov ecx, dword ptr [esi + 4]
// 008225a6  c70694509f00         mov dword ptr [esi], 0x9f5094
// 008225ac  85c9                 test ecx, ecx
// 008225ae  7405                 je 0x8225b5
// 008225b0  e82718fdff           call 0x7f3ddc
// 008225b5  f644240801           test byte ptr [esp + 8], 1
// 008225ba  7409                 je 0x8225c5
// 008225bc  56                   push esi
// 008225bd  e89812fdff           call 0x7f385a
// 008225c2  83c404               add esp, 4
// 008225c5  8bc6                 mov eax, esi
// 008225c7  5e                   pop esi
// 008225c8  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarCaptionBarControl.cpp (function ??_G?$CXTPSmartPtrInternalT@VCXTPCalendarCaptionBarThemePart@@@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarCaptionBarControl.cpp
