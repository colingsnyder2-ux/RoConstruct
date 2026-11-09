// from server: 100% by auto
// roc 2012-06 009a62e0  unit: CRobloxReportView  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a62e0
//
// 009a62e0  8b442408             mov eax, dword ptr [esp + 8]
// 009a62e4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 009a62e8  50                   push eax
// 009a62e9  e802260000           call 0x9a88f0
// 009a62ee  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\dumpstak.cpp (function ?OnError@CTraceClipboardData@@UAGXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dumpstak.cpp
