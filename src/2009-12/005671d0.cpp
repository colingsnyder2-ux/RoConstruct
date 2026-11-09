// from server: 100% by auto
// roc 2009-12 005671d0  unit: RakPeer  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005671d0
//
// 005671d0  56                   push esi
// 005671d1  8bf1                 mov esi, ecx
// 005671d3  8b4604               mov eax, dword ptr [esi + 4]
// 005671d6  8b4008               mov eax, dword ptr [eax + 8]
// 005671d9  894608               mov dword ptr [esi + 8], eax
// 005671dc  3b4604               cmp eax, dword ptr [esi + 4]
// 005671df  741e                 je 0x5671ff
// 005671e1  57                   push edi
// 005671e2  8b4e08               mov ecx, dword ptr [esi + 8]
// 005671e5  8b7908               mov edi, dword ptr [ecx + 8]
// 005671e8  8b5608               mov edx, dword ptr [esi + 8]
// 005671eb  52                   push edx
// 005671ec  e869c62800           call 0x7f385a
// 005671f1  8bc7                 mov eax, edi
// 005671f3  83c404               add esp, 4
// 005671f6  897e08               mov dword ptr [esi + 8], edi
// 005671f9  3b4604               cmp eax, dword ptr [esi + 4]
// 005671fc  75e4                 jne 0x5671e2
// 005671fe  5f                   pop edi
// 005671ff  8b4e08               mov ecx, dword ptr [esi + 8]
// 00567202  51                   push ecx
// 00567203  e852c62800           call 0x7f385a
// 00567208  83c404               add esp, 4
// 0056720b  5e                   pop esi
// 0056720c  c3                   ret 
// library raknet-4.081/ThreadsafePacketLogger.cpp (function ??1?$SingleProducerConsumer@PAD@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 ThreadsafePacketLogger.cpp
