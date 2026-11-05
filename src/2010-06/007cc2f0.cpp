// from server: 100% by auto
// roc 2010-06 007cc2f0  unit: CRobloxReportView  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007cc2f0
//
// 007cc2f0  8b442408             mov eax, dword ptr [esp + 8]
// 007cc2f4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007cc2f8  50                   push eax
// 007cc2f9  e832ff0000           call 0x7dc230
// 007cc2fe  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\dumpstak.cpp (function ?OnError@CTraceClipboardData@@UAGXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dumpstak.cpp
