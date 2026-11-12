// from server: 100% by auto
// roc 2008-06 004c2520  unit: ProfiledRakPeer  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004c2520
//
// 004c2520  6aff                 push -1
// 004c2522  681b937c00           push 0x7c931b
// 004c2527  64a100000000         mov eax, dword ptr fs:[0]
// 004c252d  50                   push eax
// 004c252e  64892500000000       mov dword ptr fs:[0], esp
// 004c2535  81ec1c010000         sub esp, 0x11c
// 004c253b  8b84242c010000       mov eax, dword ptr [esp + 0x12c]
// 004c2542  56                   push esi
// 004c2543  6a00                 push 0
// 004c2545  6a04                 push 4
// 004c2547  8bf1                 mov esi, ecx
// 004c2549  50                   push eax
// 004c254a  8d4c2418             lea ecx, [esp + 0x18]
// 004c254e  e8cd2bfeff           call 0x4a5120
// 004c2553  6a01                 push 1
// 004c2555  6a20                 push 0x20
// 004c2557  8d4c240c             lea ecx, [esp + 0xc]
// 004c255b  51                   push ecx
// 004c255c  8d4c2418             lea ecx, [esp + 0x18]
// 004c2560  c784243401000000000000 mov dword ptr [esp + 0x134], 0
// 004c256b  e8a02cfeff           call 0x4a5210
// 004c2570  8b942438010000       mov edx, dword ptr [esp + 0x138]
// 004c2577  8b842434010000       mov eax, dword ptr [esp + 0x134]
// 004c257e  52                   push edx
// 004c257f  50                   push eax
// 004c2580  8bce                 mov ecx, esi
// 004c2582  e859d9ffff           call 0x4bfee0
// 004c2587  29442404             sub dword ptr [esp + 4], eax
// 004c258b  6a00                 push 0
// 004c258d  8d4c2410             lea ecx, [esp + 0x10]
// 004c2591  e8ea2efeff           call 0x4a5480
// 004c2596  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004c259a  6a01                 push 1
// 004c259c  6a20                 push 0x20
// 004c259e  8d542410             lea edx, [esp + 0x10]
// 004c25a2  894c2410             mov dword ptr [esp + 0x10], ecx
// 004c25a6  52                   push edx
// 004c25a7  8d4c2418             lea ecx, [esp + 0x18]
// 004c25ab  e85030feff           call 0x4a5600
// 004c25b0  8d4c240c             lea ecx, [esp + 0xc]
// 004c25b4  c7842428010000ffffffff mov dword ptr [esp + 0x128], 0xffffffff
// 004c25bf  e8dc2bfeff           call 0x4a51a0
// 004c25c4  8b8c2420010000       mov ecx, dword ptr [esp + 0x120]
// 004c25cb  5e                   pop esi
// 004c25cc  64890d00000000       mov dword ptr fs:[0], ecx
// 004c25d3  81c428010000         add esp, 0x128
// 004c25d9  c20c00               ret 0xc
// library openrbx-raknet/RakPeer.cpp (function ?ShiftIncomingTimestamp@RakPeer@@IBEXPAEUSystemAddress@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
