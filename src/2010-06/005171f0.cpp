// from server: 100% by auto
// roc 2010-06 005171f0  unit: RakPeer  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005171f0
//
// 005171f0  8b442408             mov eax, dword ptr [esp + 8]
// 005171f4  8b542404             mov edx, dword ptr [esp + 4]
// 005171f8  6a00                 push 0
// 005171fa  50                   push eax
// 005171fb  52                   push edx
// 005171fc  e85ff4ffff           call 0x516660
// 00517201  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\ctltrack.cpp (function ?CreateTracker@COleControl@@IAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctltrack.cpp
