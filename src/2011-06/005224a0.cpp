// from server: 100% by auto
// roc 2011-06 005224a0  unit: RBX::Network::ProfiledRakPeer  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005224a0
//
// 005224a0  8b442408             mov eax, dword ptr [esp + 8]
// 005224a4  8b542404             mov edx, dword ptr [esp + 4]
// 005224a8  6a00                 push 0
// 005224aa  50                   push eax
// 005224ab  52                   push edx
// 005224ac  e88fe8ffff           call 0x520d40
// 005224b1  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\ctltrack.cpp (function ?CreateTracker@COleControl@@IAEXHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctltrack.cpp
