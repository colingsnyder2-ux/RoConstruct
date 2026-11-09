// from server: 100% by auto
// roc 2007-08 004bef40  unit: RakPeer  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004bef40
//
// 004bef40  8b442408             mov eax, dword ptr [esp + 8]
// 004bef44  8b542404             mov edx, dword ptr [esp + 4]
// 004bef48  6a00                 push 0
// 004bef4a  50                   push eax
// 004bef4b  52                   push edx
// 004bef4c  e87fdbffff           call 0x4bcad0
// 004bef51  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctltrack.cpp (function ?CreateTracker@COleControl@@IAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctltrack.cpp
