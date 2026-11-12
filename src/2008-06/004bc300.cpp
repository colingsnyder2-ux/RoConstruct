// from server: 100% by auto
// roc 2008-06 004bc300  unit: ProfiledRakPeer  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bc300
//
// 004bc300  56                   push esi
// 004bc301  8bf1                 mov esi, ecx
// 004bc303  8b4608               mov eax, dword ptr [esi + 8]
// 004bc306  8b8824010000         mov ecx, dword ptr [eax + 0x124]
// 004bc30c  8b5608               mov edx, dword ptr [esi + 8]
// 004bc30f  894e0c               mov dword ptr [esi + 0xc], ecx
// 004bc312  8b8224010000         mov eax, dword ptr [edx + 0x124]
// 004bc318  b901000000           mov ecx, 1
// 004bc31d  3b4608               cmp eax, dword ptr [esi + 8]
// 004bc320  743d                 je 0x4bc35f
// 004bc322  8b8024010000         mov eax, dword ptr [eax + 0x124]
// 004bc328  41                   inc ecx
// 004bc329  3b4608               cmp eax, dword ptr [esi + 8]
// 004bc32c  75f4                 jne 0x4bc322
// 004bc32e  83f908               cmp ecx, 8
// 004bc331  7e2c                 jle 0x4bc35f
// 004bc333  53                   push ebx
// 004bc334  57                   push edi
// 004bc335  8d59f8               lea ebx, [ecx - 8]
// 004bc338  eb06                 jmp 0x4bc340
// 004bc33a  8d9b00000000         lea ebx, [ebx]
// 004bc340  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bc343  8bb824010000         mov edi, dword ptr [eax + 0x124]
// 004bc349  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004bc34c  51                   push ecx
// 004bc34d  e828431e00           call 0x6a067a
// 004bc352  83c404               add esp, 4
// 004bc355  83eb01               sub ebx, 1
// 004bc358  897e0c               mov dword ptr [esi + 0xc], edi
// 004bc35b  75e3                 jne 0x4bc340
// 004bc35d  5f                   pop edi
// 004bc35e  5b                   pop ebx
// 004bc35f  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bc362  8b5608               mov edx, dword ptr [esi + 8]
// 004bc365  898224010000         mov dword ptr [edx + 0x124], eax
// 004bc36b  8b4608               mov eax, dword ptr [esi + 8]
// 004bc36e  89460c               mov dword ptr [esi + 0xc], eax
// 004bc371  8906                 mov dword ptr [esi], eax
// 004bc373  894604               mov dword ptr [esi + 4], eax
// 004bc376  33c0                 xor eax, eax
// 004bc378  894614               mov dword ptr [esi + 0x14], eax
// 004bc37b  894610               mov dword ptr [esi + 0x10], eax
// 004bc37e  5e                   pop esi
// 004bc37f  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ?Clear@?$SingleProducerConsumer@URequestedConnectionStruct@RakPeer@@@DataStructures@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
