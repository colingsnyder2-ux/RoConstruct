// from server: 100% by auto
// roc 2008-06 004bc400  unit: ProfiledRakPeer  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc400
//
// 004bc400  56                   push esi
// 004bc401  8bf1                 mov esi, ecx
// 004bc403  8b4604               mov eax, dword ptr [esi + 4]
// 004bc406  8b403c               mov eax, dword ptr [eax + 0x3c]
// 004bc409  894608               mov dword ptr [esi + 8], eax
// 004bc40c  3b4604               cmp eax, dword ptr [esi + 4]
// 004bc40f  741e                 je 0x4bc42f
// 004bc411  57                   push edi
// 004bc412  8b4e08               mov ecx, dword ptr [esi + 8]
// 004bc415  8b793c               mov edi, dword ptr [ecx + 0x3c]
// 004bc418  8b5608               mov edx, dword ptr [esi + 8]
// 004bc41b  52                   push edx
// 004bc41c  e859421e00           call 0x6a067a
// 004bc421  8bc7                 mov eax, edi
// 004bc423  83c404               add esp, 4
// 004bc426  897e08               mov dword ptr [esi + 8], edi
// 004bc429  3b4604               cmp eax, dword ptr [esi + 4]
// 004bc42c  75e4                 jne 0x4bc412
// 004bc42e  5f                   pop edi
// 004bc42f  8b4e08               mov ecx, dword ptr [esi + 8]
// 004bc432  51                   push ecx
// 004bc433  e842421e00           call 0x6a067a
// 004bc438  83c404               add esp, 4
// 004bc43b  5e                   pop esi
// 004bc43c  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??1?$SingleProducerConsumer@UBufferedCommandStruct@RakPeer@@@DataStructures@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
