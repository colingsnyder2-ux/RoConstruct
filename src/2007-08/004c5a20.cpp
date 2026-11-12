// from server: 100% by auto
// roc 2007-08 004c5a20  unit: RakPeer  size: 212 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004c5a20
//
// 004c5a20  8b542404             mov edx, dword ptr [esp + 4]
// 004c5a24  56                   push esi
// 004c5a25  8b7240               mov esi, dword ptr [edx + 0x40]
// 004c5a28  8b4604               mov eax, dword ptr [esi + 4]
// 004c5a2b  85c0                 test eax, eax
// 004c5a2d  7568                 jne 0x4c5a97
// 004c5a2f  8b06                 mov eax, dword ptr [esi]
// 004c5a31  8910                 mov dword ptr [eax], edx
// 004c5a33  83460401             add dword ptr [esi + 4], 1
// 004c5a37  83410cff             add dword ptr [ecx + 0xc], -1
// 004c5a3b  8b560c               mov edx, dword ptr [esi + 0xc]
// 004c5a3e  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c5a41  894210               mov dword ptr [edx + 0x10], eax
// 004c5a44  8b5610               mov edx, dword ptr [esi + 0x10]
// 004c5a47  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c5a4a  89420c               mov dword ptr [edx + 0xc], eax
// 004c5a4d  83790c00             cmp dword ptr [ecx + 0xc], 0
// 004c5a51  7e0d                 jle 0x4c5a60
// 004c5a53  8b4104               mov eax, dword ptr [ecx + 4]
// 004c5a56  3bf0                 cmp esi, eax
// 004c5a58  7506                 jne 0x4c5a60
// 004c5a5a  8b500c               mov edx, dword ptr [eax + 0xc]
// 004c5a5d  895104               mov dword ptr [ecx + 4], edx
// 004c5a60  8b4108               mov eax, dword ptr [ecx + 8]
// 004c5a63  85c0                 test eax, eax
// 004c5a65  8d5001               lea edx, [eax + 1]
// 004c5a68  895108               mov dword ptr [ecx + 8], edx
// 004c5a6b  750c                 jne 0x4c5a79
// 004c5a6d  8931                 mov dword ptr [ecx], esi
// 004c5a6f  89760c               mov dword ptr [esi + 0xc], esi
// 004c5a72  897610               mov dword ptr [esi + 0x10], esi
// 004c5a75  5e                   pop esi
// 004c5a76  c20400               ret 4
// 004c5a79  8b01                 mov eax, dword ptr [ecx]
// 004c5a7b  89460c               mov dword ptr [esi + 0xc], eax
// 004c5a7e  8b11                 mov edx, dword ptr [ecx]
// 004c5a80  8b4210               mov eax, dword ptr [edx + 0x10]
// 004c5a83  894610               mov dword ptr [esi + 0x10], eax
// 004c5a86  8b11                 mov edx, dword ptr [ecx]
// 004c5a88  8b4210               mov eax, dword ptr [edx + 0x10]
// 004c5a8b  89700c               mov dword ptr [eax + 0xc], esi
// 004c5a8e  8b09                 mov ecx, dword ptr [ecx]
// 004c5a90  897110               mov dword ptr [ecx + 0x10], esi
// 004c5a93  5e                   pop esi
// 004c5a94  c20400               ret 4
// 004c5a97  57                   push edi
// 004c5a98  8b3e                 mov edi, dword ptr [esi]
// 004c5a9a  891487               mov dword ptr [edi + eax*4], edx
// 004c5a9d  83460401             add dword ptr [esi + 4], 1
// 004c5aa1  8b7e04               mov edi, dword ptr [esi + 4]
// 004c5aa4  b8398ee338           mov eax, 0x38e38e39
// 004c5aa9  f76110               mul dword ptr [ecx + 0x10]
// 004c5aac  c1ea04               shr edx, 4
// 004c5aaf  3bfa                 cmp edi, edx
// 004c5ab1  753c                 jne 0x4c5aef
// 004c5ab3  83790804             cmp dword ptr [ecx + 8], 4
// 004c5ab7  7c36                 jl 0x4c5aef
// 004c5ab9  3b31                 cmp esi, dword ptr [ecx]
// 004c5abb  7505                 jne 0x4c5ac2
// 004c5abd  8b560c               mov edx, dword ptr [esi + 0xc]
// 004c5ac0  8911                 mov dword ptr [ecx], edx
// 004c5ac2  8b4610               mov eax, dword ptr [esi + 0x10]
// 004c5ac5  8b560c               mov edx, dword ptr [esi + 0xc]
// 004c5ac8  8b3dc4e67700         mov edi, dword ptr [0x77e6c4]
// 004c5ace  89500c               mov dword ptr [eax + 0xc], edx
// 004c5ad1  8b460c               mov eax, dword ptr [esi + 0xc]
// 004c5ad4  8b5610               mov edx, dword ptr [esi + 0x10]
// 004c5ad7  895010               mov dword ptr [eax + 0x10], edx
// 004c5ada  834108ff             add dword ptr [ecx + 8], -1
// 004c5ade  8b06                 mov eax, dword ptr [esi]
// 004c5ae0  50                   push eax
// 004c5ae1  ffd7                 call edi
// 004c5ae3  8b4e08               mov ecx, dword ptr [esi + 8]
// 004c5ae6  51                   push ecx
// 004c5ae7  ffd7                 call edi
// 004c5ae9  56                   push esi
// 004c5aea  ffd7                 call edi
// 004c5aec  83c40c               add esp, 0xc
// 004c5aef  5f                   pop edi
// 004c5af0  5e                   pop esi
// 004c5af1  c20400               ret 4
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Release@?$MemoryPool@UInternalPacket@@@DataStructures@@QAEXPAUInternalPacket@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
