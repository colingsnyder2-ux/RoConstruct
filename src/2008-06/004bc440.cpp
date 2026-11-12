// from server: 100% by auto
// roc 2008-06 004bc440  unit: ProfiledRakPeer  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc440
//
// 004bc440  56                   push esi
// 004bc441  8bf1                 mov esi, ecx
// 004bc443  8b4604               mov eax, dword ptr [esi + 4]
// 004bc446  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 004bc449  3b4e08               cmp ecx, dword ptr [esi + 8]
// 004bc44c  740e                 je 0x4bc45c
// 004bc44e  8b5604               mov edx, dword ptr [esi + 4]
// 004bc451  8b423c               mov eax, dword ptr [edx + 0x3c]
// 004bc454  8a4838               mov cl, byte ptr [eax + 0x38]
// 004bc457  80f901               cmp cl, 1
// 004bc45a  7521                 jne 0x4bc47d
// 004bc45c  8b5604               mov edx, dword ptr [esi + 4]
// 004bc45f  57                   push edi
// 004bc460  8b7a3c               mov edi, dword ptr [edx + 0x3c]
// 004bc463  6a40                 push 0x40
// 004bc465  e8b6441e00           call 0x6a0920
// 004bc46a  8b4e04               mov ecx, dword ptr [esi + 4]
// 004bc46d  89413c               mov dword ptr [ecx + 0x3c], eax
// 004bc470  8b5604               mov edx, dword ptr [esi + 4]
// 004bc473  8b423c               mov eax, dword ptr [edx + 0x3c]
// 004bc476  83c404               add esp, 4
// 004bc479  89783c               mov dword ptr [eax + 0x3c], edi
// 004bc47c  5f                   pop edi
// 004bc47d  8b4604               mov eax, dword ptr [esi + 4]
// 004bc480  8b483c               mov ecx, dword ptr [eax + 0x3c]
// 004bc483  894e04               mov dword ptr [esi + 4], ecx
// 004bc486  5e                   pop esi
// 004bc487  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?WriteLock@?$SingleProducerConsumer@UBufferedCommandStruct@RakPeer@@@DataStructures@@QAEPAUBufferedCommandStruct@RakPeer@@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
