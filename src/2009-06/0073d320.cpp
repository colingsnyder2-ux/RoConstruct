// from server: 100% by auto
// roc 2009-06 0073d320  unit: CRobloxReportView  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0073d320
//
// 0073d320  8b442408             mov eax, dword ptr [esp + 8]
// 0073d324  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0073d328  50                   push eax
// 0073d329  e8c2000100           call 0x74d3f0
// 0073d32e  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\dumpstak.cpp (function ?OnError@CTraceClipboardData@@UAGXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dumpstak.cpp
