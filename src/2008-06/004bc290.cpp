// from server: 100% by auto
// roc 2008-06 004bc290  unit: ProfiledRakPeer  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc290
//
// 004bc290  56                   push esi
// 004bc291  8bf1                 mov esi, ecx
// 004bc293  8b4604               mov eax, dword ptr [esi + 4]
// 004bc296  8b8824010000         mov ecx, dword ptr [eax + 0x124]
// 004bc29c  3b4e08               cmp ecx, dword ptr [esi + 8]
// 004bc29f  7414                 je 0x4bc2b5
// 004bc2a1  8b5604               mov edx, dword ptr [esi + 4]
// 004bc2a4  8b8224010000         mov eax, dword ptr [edx + 0x124]
// 004bc2aa  8a8820010000         mov cl, byte ptr [eax + 0x120]
// 004bc2b0  80f901               cmp cl, 1
// 004bc2b3  7530                 jne 0x4bc2e5
// 004bc2b5  8b5604               mov edx, dword ptr [esi + 4]
// 004bc2b8  57                   push edi
// 004bc2b9  8bba24010000         mov edi, dword ptr [edx + 0x124]
// 004bc2bf  6828010000           push 0x128
// 004bc2c4  e857461e00           call 0x6a0920
// 004bc2c9  8b4e04               mov ecx, dword ptr [esi + 4]
// 004bc2cc  898124010000         mov dword ptr [ecx + 0x124], eax
// 004bc2d2  8b5604               mov edx, dword ptr [esi + 4]
// 004bc2d5  8b8224010000         mov eax, dword ptr [edx + 0x124]
// 004bc2db  83c404               add esp, 4
// 004bc2de  89b824010000         mov dword ptr [eax + 0x124], edi
// 004bc2e4  5f                   pop edi
// 004bc2e5  8b4604               mov eax, dword ptr [esi + 4]
// 004bc2e8  8b8824010000         mov ecx, dword ptr [eax + 0x124]
// 004bc2ee  894e04               mov dword ptr [esi + 4], ecx
// 004bc2f1  5e                   pop esi
// 004bc2f2  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?WriteLock@?$SingleProducerConsumer@URequestedConnectionStruct@RakPeer@@@DataStructures@@QAEPAURequestedConnectionStruct@RakPeer@@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
