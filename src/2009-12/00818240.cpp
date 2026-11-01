// from server: 100% by auto
// roc 2009-12 00818240  unit: CRobloxReportView  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00818240
//
// 00818240  8b442408             mov eax, dword ptr [esp + 8]
// 00818244  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00818248  50                   push eax
// 00818249  e862ff0000           call 0x8281b0
// 0081824e  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dumpstak.cpp (function ?OnError@CTraceClipboardData@@UAGXPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dumpstak.cpp
