// from server: 100% by auto
// roc 2009-12 00567210  unit: RakPeer  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00567210
//
// 00567210  56                   push esi
// 00567211  8bf1                 mov esi, ecx
// 00567213  8b4604               mov eax, dword ptr [esi + 4]
// 00567216  8b4808               mov ecx, dword ptr [eax + 8]
// 00567219  3b4e08               cmp ecx, dword ptr [esi + 8]
// 0056721c  740e                 je 0x56722c
// 0056721e  8b5604               mov edx, dword ptr [esi + 4]
// 00567221  8b4208               mov eax, dword ptr [edx + 8]
// 00567224  8a4804               mov cl, byte ptr [eax + 4]
// 00567227  80f901               cmp cl, 1
// 0056722a  752d                 jne 0x567259
// 0056722c  8b5604               mov edx, dword ptr [esi + 4]
// 0056722f  57                   push edi
// 00567230  8b7a08               mov edi, dword ptr [edx + 8]
// 00567233  6a0c                 push 0xc
// 00567235  e826c62800           call 0x7f3860
// 0056723a  83c404               add esp, 4
// 0056723d  85c0                 test eax, eax
// 0056723f  7406                 je 0x567247
// 00567241  c6400400             mov byte ptr [eax + 4], 0
// 00567245  eb02                 jmp 0x567249
// 00567247  33c0                 xor eax, eax
// 00567249  8b4e04               mov ecx, dword ptr [esi + 4]
// 0056724c  894108               mov dword ptr [ecx + 8], eax
// 0056724f  8b5604               mov edx, dword ptr [esi + 4]
// 00567252  8b4208               mov eax, dword ptr [edx + 8]
// 00567255  897808               mov dword ptr [eax + 8], edi
// 00567258  5f                   pop edi
// 00567259  8b4604               mov eax, dword ptr [esi + 4]
// 0056725c  8b4808               mov ecx, dword ptr [eax + 8]
// 0056725f  894e04               mov dword ptr [esi + 4], ecx
// 00567262  5e                   pop esi
// 00567263  c3                   ret 
// library raknet-4.081/ThreadsafePacketLogger.cpp (function ?WriteLock@?$SingleProducerConsumer@PAD@DataStructures@@QAEPAPADXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 ThreadsafePacketLogger.cpp
