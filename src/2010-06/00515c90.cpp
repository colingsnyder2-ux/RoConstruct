// from server: 100% by auto
// roc 2010-06 00515c90  unit: RakPeer  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00515c90
//
// 00515c90  56                   push esi
// 00515c91  8bf1                 mov esi, ecx
// 00515c93  8b4604               mov eax, dword ptr [esi + 4]
// 00515c96  8b4808               mov ecx, dword ptr [eax + 8]
// 00515c99  3b4e08               cmp ecx, dword ptr [esi + 8]
// 00515c9c  740e                 je 0x515cac
// 00515c9e  8b5604               mov edx, dword ptr [esi + 4]
// 00515ca1  8b4208               mov eax, dword ptr [edx + 8]
// 00515ca4  8a4804               mov cl, byte ptr [eax + 4]
// 00515ca7  80f901               cmp cl, 1
// 00515caa  752d                 jne 0x515cd9
// 00515cac  8b5604               mov edx, dword ptr [esi + 4]
// 00515caf  57                   push edi
// 00515cb0  8b7a08               mov edi, dword ptr [edx + 8]
// 00515cb3  6a0c                 push 0xc
// 00515cb5  e8e61c2900           call 0x7a79a0
// 00515cba  83c404               add esp, 4
// 00515cbd  85c0                 test eax, eax
// 00515cbf  7406                 je 0x515cc7
// 00515cc1  c6400400             mov byte ptr [eax + 4], 0
// 00515cc5  eb02                 jmp 0x515cc9
// 00515cc7  33c0                 xor eax, eax
// 00515cc9  8b4e04               mov ecx, dword ptr [esi + 4]
// 00515ccc  894108               mov dword ptr [ecx + 8], eax
// 00515ccf  8b5604               mov edx, dword ptr [esi + 4]
// 00515cd2  8b4208               mov eax, dword ptr [edx + 8]
// 00515cd5  897808               mov dword ptr [eax + 8], edi
// 00515cd8  5f                   pop edi
// 00515cd9  8b4604               mov eax, dword ptr [esi + 4]
// 00515cdc  8b4808               mov ecx, dword ptr [eax + 8]
// 00515cdf  894e04               mov dword ptr [esi + 4], ecx
// 00515ce2  5e                   pop esi
// 00515ce3  c3                   ret 
// library raknet-4.081/ThreadsafePacketLogger.cpp (function ?WriteLock@?$SingleProducerConsumer@PAD@DataStructures@@QAEPAPADXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 ThreadsafePacketLogger.cpp
