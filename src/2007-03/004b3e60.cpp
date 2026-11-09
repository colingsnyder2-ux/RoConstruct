// from server: 100% by auto
// roc 2007-03 004b3e60  unit: seg_004b0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004b3e60
//
// 004b3e60  8b442408             mov eax, dword ptr [esp + 8]
// 004b3e64  8b542404             mov edx, dword ptr [esp + 4]
// 004b3e68  6a00                 push 0
// 004b3e6a  50                   push eax
// 004b3e6b  52                   push edx
// 004b3e6c  e8dfdcffff           call 0x4b1b50
// 004b3e71  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctltrack.cpp (function ?CreateTracker@COleControl@@IAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctltrack.cpp
