// from server: 100% by auto
// roc 2008-06 004c1b60  unit: ProfiledRakPeer  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c1b60
//
// 004c1b60  8b442408             mov eax, dword ptr [esp + 8]
// 004c1b64  8b542404             mov edx, dword ptr [esp + 4]
// 004c1b68  6a00                 push 0
// 004c1b6a  50                   push eax
// 004c1b6b  52                   push edx
// 004c1b6c  e8bfe1ffff           call 0x4bfd30
// 004c1b71  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\ctltrack.cpp (function ?CreateTracker@COleControl@@IAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctltrack.cpp
