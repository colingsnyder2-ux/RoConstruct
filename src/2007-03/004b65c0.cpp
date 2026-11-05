// from server: 100% by auto
// roc 2007-03 004b65c0  unit: seg_004b0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004b65c0
//
// 004b65c0  8b442408             mov eax, dword ptr [esp + 8]
// 004b65c4  8b542404             mov edx, dword ptr [esp + 4]
// 004b65c8  6a00                 push 0
// 004b65ca  50                   push eax
// 004b65cb  52                   push edx
// 004b65cc  e83fe3ffff           call 0x4b4910
// 004b65d1  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctltrack.cpp (function ?CreateTracker@COleControl@@IAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctltrack.cpp
