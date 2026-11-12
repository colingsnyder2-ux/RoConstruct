// from server: 100% by colin
// roc 2007-08 004b8b40  unit: RakPeer  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b8b40
//
// 004b8b40  8b442404             mov eax, dword ptr [esp + 4]
// 004b8b44  85c0                 test eax, eax
// 004b8b46  7414                 je 0x4b8b5c
// 004b8b48  803800               cmp byte ptr [eax], 0
// 004b8b4b  740f                 je 0x4b8b5c
// 004b8b4d  89442404             mov dword ptr [esp + 4], eax
// 004b8b51  81c1fc060000         add ecx, 0x6fc
// 004b8b57  e9d4150100           jmp 0x4ca130
// 004b8b5c  c20400               ret 4
// copied from an identical function in another client (function ?UnregisterAsRemoteProcedureCall@RakPeer@@UAEXPBD@Z)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp