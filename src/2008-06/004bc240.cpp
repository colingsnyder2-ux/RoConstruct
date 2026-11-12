// from server: 100% by auto
// roc 2008-06 004bc240  unit: ProfiledRakPeer  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc240
//
// 004bc240  56                   push esi
// 004bc241  8bf1                 mov esi, ecx
// 004bc243  8b4604               mov eax, dword ptr [esi + 4]
// 004bc246  8b8024010000         mov eax, dword ptr [eax + 0x124]
// 004bc24c  894608               mov dword ptr [esi + 8], eax
// 004bc24f  3b4604               cmp eax, dword ptr [esi + 4]
// 004bc252  742c                 je 0x4bc280
// 004bc254  57                   push edi
// 004bc255  eb09                 jmp 0x4bc260
// 004bc257  8da42400000000       lea esp, [esp]
// 004bc25e  8bff                 mov edi, edi
// 004bc260  8b4e08               mov ecx, dword ptr [esi + 8]
// 004bc263  8bb924010000         mov edi, dword ptr [ecx + 0x124]
// 004bc269  8b5608               mov edx, dword ptr [esi + 8]
// 004bc26c  52                   push edx
// 004bc26d  e808441e00           call 0x6a067a
// 004bc272  8bc7                 mov eax, edi
// 004bc274  83c404               add esp, 4
// 004bc277  897e08               mov dword ptr [esi + 8], edi
// 004bc27a  3b4604               cmp eax, dword ptr [esi + 4]
// 004bc27d  75e1                 jne 0x4bc260
// 004bc27f  5f                   pop edi
// 004bc280  8b4e08               mov ecx, dword ptr [esi + 8]
// 004bc283  51                   push ecx
// 004bc284  e8f1431e00           call 0x6a067a
// 004bc289  83c404               add esp, 4
// 004bc28c  5e                   pop esi
// 004bc28d  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??1?$SingleProducerConsumer@URequestedConnectionStruct@RakPeer@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
