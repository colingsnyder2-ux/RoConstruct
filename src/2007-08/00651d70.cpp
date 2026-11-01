// from server: 100% by auto
// roc 2007-08 00651d70  unit: CRobloxReportView  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00651d70
//
// 00651d70  8b442404             mov eax, dword ptr [esp + 4]
// 00651d74  56                   push esi
// 00651d75  50                   push eax
// 00651d76  8bf1                 mov esi, ecx
// 00651d78  e8a5ebfdff           call 0x630922
// 00651d7d  8b16                 mov edx, dword ptr [esi]
// 00651d7f  8b828c010000         mov eax, dword ptr [edx + 0x18c]
// 00651d85  8bce                 mov ecx, esi
// 00651d87  ffd0                 call eax
// 00651d89  8bc8                 mov ecx, eax
// 00651d8b  e874e2fdff           call 0x630004
// 00651d90  5e                   pop esi
// 00651d91  c20400               ret 4
// library xtp-15.2.1/Source\Calendar\XTPCalendarControlView.cpp (function ?OnSetFocus@CXTPCalendarControlView@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Calendar/XTPCalendarControlView.cpp
