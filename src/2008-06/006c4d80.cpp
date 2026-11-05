// from server: 100% by auto
// roc 2008-06 006c4d80  unit: CRobloxReportView  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006c4d80
//
// 006c4d80  8b442408             mov eax, dword ptr [esp + 8]
// 006c4d84  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006c4d88  50                   push eax
// 006c4d89  e8f2fe0000           call 0x6d4c80
// 006c4d8e  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\dumpstak.cpp (function ?OnError@CTraceClipboardData@@UAGXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dumpstak.cpp
