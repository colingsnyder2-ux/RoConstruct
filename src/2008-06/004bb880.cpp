// from server: 100% by auto
// roc 2008-06 004bb880  unit: ProfiledRakPeer  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb880
//
// 004bb880  8b442404             mov eax, dword ptr [esp + 4]
// 004bb884  85c0                 test eax, eax
// 004bb886  741c                 je 0x4bb8a4
// 004bb888  803800               cmp byte ptr [eax], 0
// 004bb88b  7417                 je 0x4bb8a4
// 004bb88d  8b542408             mov edx, dword ptr [esp + 8]
// 004bb891  85d2                 test edx, edx
// 004bb893  740f                 je 0x4bb8a4
// 004bb895  6a00                 push 0
// 004bb897  52                   push edx
// 004bb898  50                   push eax
// 004bb899  81c1fc060000         add ecx, 0x6fc
// 004bb89f  e8ec840100           call 0x4d3d90
// 004bb8a4  c20800               ret 8
// library openrbx-raknet/RakPeer.cpp (function ?RegisterAsRemoteProcedureCall@RakPeer@@UAEXPBDP6AXPAURPCParameters@@@Z@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
