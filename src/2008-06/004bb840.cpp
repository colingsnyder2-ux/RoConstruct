// from server: 100% by auto
// roc 2008-06 004bb840  unit: ProfiledRakPeer  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bb840
//
// 004bb840  56                   push esi
// 004bb841  8b742408             mov esi, dword ptr [esp + 8]
// 004bb845  85f6                 test esi, esi
// 004bb847  741c                 je 0x4bb865
// 004bb849  807e1800             cmp byte ptr [esi + 0x18], 0
// 004bb84d  740c                 je 0x4bb85b
// 004bb84f  8b4614               mov eax, dword ptr [esi + 0x14]
// 004bb852  50                   push eax
// 004bb853  e8224e1e00           call 0x6a067a
// 004bb858  83c404               add esp, 4
// 004bb85b  56                   push esi
// 004bb85c  ff15c0288000         call dword ptr [0x8028c0]
// 004bb862  83c404               add esp, 4
// 004bb865  5e                   pop esi
// 004bb866  c20400               ret 4
// library openrbx-raknet/RakPeer.cpp (function ?DeallocatePacket@RakPeer@@UAEXPAUPacket@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
