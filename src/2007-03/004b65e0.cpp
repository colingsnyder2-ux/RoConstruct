// from server: 100% by auto
// roc 2007-03 004b65e0  unit: seg_004b0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004b65e0
//
// 004b65e0  8b442408             mov eax, dword ptr [esp + 8]
// 004b65e4  8b542404             mov edx, dword ptr [esp + 4]
// 004b65e8  6a00                 push 0
// 004b65ea  50                   push eax
// 004b65eb  52                   push edx
// 004b65ec  e8cfe1ffff           call 0x4b47c0
// 004b65f1  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctltrack.cpp (function ?CreateTracker@COleControl@@IAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctltrack.cpp
