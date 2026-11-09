// from server: 100% by auto
// roc 2009-12 005688a0  unit: RakPeer  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005688a0
//
// 005688a0  8b442408             mov eax, dword ptr [esp + 8]
// 005688a4  8b542404             mov edx, dword ptr [esp + 4]
// 005688a8  6a00                 push 0
// 005688aa  50                   push eax
// 005688ab  52                   push edx
// 005688ac  e85ff4ffff           call 0x567d10
// 005688b1  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctltrack.cpp (function ?CreateTracker@COleControl@@IAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctltrack.cpp
