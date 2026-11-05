// from server: 100% by auto
// roc 2007-08 00475860  unit: CInstanceRecord::CNameItem  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00475860
//
// 00475860  8b442408             mov eax, dword ptr [esp + 8]
// 00475864  8b542404             mov edx, dword ptr [esp + 4]
// 00475868  6a00                 push 0
// 0047586a  50                   push eax
// 0047586b  52                   push edx
// 0047586c  e88ff4ffff           call 0x474d00
// 00475871  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctltrack.cpp (function ?CreateTracker@COleControl@@IAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctltrack.cpp
