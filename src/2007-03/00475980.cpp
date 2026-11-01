// from server: 100% by auto
// roc 2007-03 00475980  unit: seg_00470000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00475980
//
// 00475980  8b442408             mov eax, dword ptr [esp + 8]
// 00475984  8b542404             mov edx, dword ptr [esp + 4]
// 00475988  6a00                 push 0
// 0047598a  50                   push eax
// 0047598b  52                   push edx
// 0047598c  e86ff4ffff           call 0x474e00
// 00475991  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctltrack.cpp (function ?CreateTracker@COleControl@@IAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctltrack.cpp
