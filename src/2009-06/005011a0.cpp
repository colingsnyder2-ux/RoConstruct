// from server: 100% by auto
// roc 2009-06 005011a0  unit: RakPeer  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005011a0
//
// 005011a0  8b442408             mov eax, dword ptr [esp + 8]
// 005011a4  8b542404             mov edx, dword ptr [esp + 4]
// 005011a8  6a00                 push 0
// 005011aa  50                   push eax
// 005011ab  52                   push edx
// 005011ac  e85ff4ffff           call 0x500610
// 005011b1  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\ctltrack.cpp (function ?CreateTracker@COleControl@@IAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctltrack.cpp
