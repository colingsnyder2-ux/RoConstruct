// from server: 100% by auto
// roc 2007-08 00651dc0  unit: CRobloxReportView  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00651dc0
//
// 00651dc0  8b442408             mov eax, dword ptr [esp + 8]
// 00651dc4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00651dc8  50                   push eax
// 00651dc9  e892cd0000           call 0x65eb60
// 00651dce  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dumpstak.cpp (function ?OnError@CTraceClipboardData@@UAGXPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dumpstak.cpp
