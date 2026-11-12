// from server: 100% by colin
// roc 2007-08 004b9450  unit: RakPeer  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b9450
//
// 004b9450  56                   push esi
// 004b9451  8bf1                 mov esi, ecx
// 004b9453  8b4604               mov eax, dword ptr [esi + 4]
// 004b9456  8b8824010000         mov ecx, dword ptr [eax + 0x124]
// 004b945c  3b4e08               cmp ecx, dword ptr [esi + 8]
// 004b945f  7414                 je 0x4b9475
// 004b9461  8b5604               mov edx, dword ptr [esi + 4]
// 004b9464  8b8224010000         mov eax, dword ptr [edx + 0x124]
// 004b946a  8a8820010000         mov cl, byte ptr [eax + 0x120]
// 004b9470  80f901               cmp cl, 1
// 004b9473  7530                 jne 0x4b94a5
// 004b9475  8b5604               mov edx, dword ptr [esi + 4]
// 004b9478  57                   push edi
// 004b9479  8bba24010000         mov edi, dword ptr [edx + 0x124]
// 004b947f  6828010000           push 0x128
// 004b9484  e86d6a1700           call 0x62fef6
// 004b9489  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b948c  898124010000         mov dword ptr [ecx + 0x124], eax
// 004b9492  8b5604               mov edx, dword ptr [esi + 4]
// 004b9495  8b8224010000         mov eax, dword ptr [edx + 0x124]
// 004b949b  83c404               add esp, 4
// 004b949e  89b824010000         mov dword ptr [eax + 0x124], edi
// 004b94a4  5f                   pop edi
// 004b94a5  8b4604               mov eax, dword ptr [esi + 4]
// 004b94a8  8b8824010000         mov ecx, dword ptr [eax + 0x124]
// 004b94ae  894e04               mov dword ptr [esi + 4], ecx
// 004b94b1  5e                   pop esi
// 004b94b2  c3                   ret 
// copied from an identical function in another client (function ?WriteLock@?$SingleProducerConsumer@URequestedConnectionStruct@RakPeer@@@DataStructures@@QAEPAURequestedConnectionStruct@RakPeer@@XZ)

// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-raknet RakPeer.cpp