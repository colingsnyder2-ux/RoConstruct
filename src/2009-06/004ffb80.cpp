// from server: 100% by auto
// roc 2009-06 004ffb80  unit: RakPeer  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ffb80
//
// 004ffb80  56                   push esi
// 004ffb81  8bf1                 mov esi, ecx
// 004ffb83  8b4604               mov eax, dword ptr [esi + 4]
// 004ffb86  8b4808               mov ecx, dword ptr [eax + 8]
// 004ffb89  3b4e08               cmp ecx, dword ptr [esi + 8]
// 004ffb8c  740e                 je 0x4ffb9c
// 004ffb8e  8b5604               mov edx, dword ptr [esi + 4]
// 004ffb91  8b4208               mov eax, dword ptr [edx + 8]
// 004ffb94  8a4804               mov cl, byte ptr [eax + 4]
// 004ffb97  80f901               cmp cl, 1
// 004ffb9a  752d                 jne 0x4ffbc9
// 004ffb9c  8b5604               mov edx, dword ptr [esi + 4]
// 004ffb9f  57                   push edi
// 004ffba0  8b7a08               mov edi, dword ptr [edx + 8]
// 004ffba3  6a0c                 push 0xc
// 004ffba5  e88e8e2100           call 0x718a38
// 004ffbaa  83c404               add esp, 4
// 004ffbad  85c0                 test eax, eax
// 004ffbaf  7406                 je 0x4ffbb7
// 004ffbb1  c6400400             mov byte ptr [eax + 4], 0
// 004ffbb5  eb02                 jmp 0x4ffbb9
// 004ffbb7  33c0                 xor eax, eax
// 004ffbb9  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ffbbc  894108               mov dword ptr [ecx + 8], eax
// 004ffbbf  8b5604               mov edx, dword ptr [esi + 4]
// 004ffbc2  8b4208               mov eax, dword ptr [edx + 8]
// 004ffbc5  897808               mov dword ptr [eax + 8], edi
// 004ffbc8  5f                   pop edi
// 004ffbc9  8b4604               mov eax, dword ptr [esi + 4]
// 004ffbcc  8b4808               mov ecx, dword ptr [eax + 8]
// 004ffbcf  894e04               mov dword ptr [esi + 4], ecx
// 004ffbd2  5e                   pop esi
// 004ffbd3  c3                   ret 
// library raknet-4.081/ThreadsafePacketLogger.cpp (function ?WriteLock@?$SingleProducerConsumer@PAD@DataStructures@@QAEPAPADXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 ThreadsafePacketLogger.cpp
