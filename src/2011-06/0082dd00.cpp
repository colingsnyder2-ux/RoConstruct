// from server: 100% by auto
// roc 2011-06 0082dd00  unit: CRobloxReportView  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082dd00
//
// 0082dd00  8b442408             mov eax, dword ptr [esp + 8]
// 0082dd04  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0082dd08  50                   push eax
// 0082dd09  e8f2250000           call 0x830300
// 0082dd0e  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\dumpstak.cpp (function ?OnError@CTraceClipboardData@@UAGXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dumpstak.cpp
