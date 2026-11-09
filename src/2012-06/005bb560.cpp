// roc 2012-06 005bb560  unit: RakNet::RakPeer  size: 204 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005bb560
//
// 005bb560  53                   push ebx
// 005bb561  55                   push ebp
// 005bb562  56                   push esi
// 005bb563  57                   push edi
// 005bb564  e867d4ffff           call 0x5b89d0
// 005bb569  8b742418             mov esi, dword ptr [esp + 0x18]
// 005bb56d  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005bb571  33ff                 xor edi, edi
// 005bb573  3bd6                 cmp edx, esi
// 005bb575  7214                 jb 0x5bb58b
// 005bb577  7704                 ja 0x5bb57d
// 005bb579  3bc3                 cmp eax, ebx
// 005bb57b  760e                 jbe 0x5bb58b
// 005bb57d  8bf8                 mov edi, eax
// 005bb57f  2bfb                 sub edi, ebx
// 005bb581  8bca                 mov ecx, edx
// 005bb583  1bce                 sbb ecx, esi
// 005bb585  894c2418             mov dword ptr [esp + 0x18], ecx
// 005bb589  eb04                 jmp 0x5bb58f
// 005bb58b  897c2418             mov dword ptr [esp + 0x18], edi
// 005bb58f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005bb593  8ba9b8110000         mov ebp, dword ptr [ecx + 0x11b8]
// 005bb599  0facd001             shrd eax, edx, 1
// 005bb59d  c1e504               shl ebp, 4
// 005bb5a0  6689bc2968110000     mov word ptr [ecx + ebp + 0x1168], di
// 005bb5a8  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 005bb5ac  d1ea                 shr edx, 1
// 005bb5ae  2be8                 sub ebp, eax
// 005bb5b0  8b442420             mov eax, dword ptr [esp + 0x20]
// 005bb5b4  1bc2                 sbb eax, edx
// 005bb5b6  0facf301             shrd ebx, esi, 1
// 005bb5ba  d1ee                 shr esi, 1
// 005bb5bc  2beb                 sub ebp, ebx
// 005bb5be  1bc6                 sbb eax, esi
// 005bb5c0  8bd0                 mov edx, eax
// 005bb5c2  8b81b8110000         mov eax, dword ptr [ecx + 0x11b8]
// 005bb5c8  0517010000           add eax, 0x117
// 005bb5cd  c1e004               shl eax, 4
// 005bb5d0  892c08               mov dword ptr [eax + ecx], ebp
// 005bb5d3  89540804             mov dword ptr [eax + ecx + 4], edx
// 005bb5d7  0fb781c0110000       movzx eax, word ptr [ecx + 0x11c0]
// 005bb5de  baffff0000           mov edx, 0xffff
// 005bb5e3  663bc2               cmp ax, dx
// 005bb5e6  7407                 je 0x5bb5ef
// 005bb5e8  0fb7c0               movzx eax, ax
// 005bb5eb  3bc7                 cmp eax, edi
// 005bb5ed  7e07                 jle 0x5bb5f6
// 005bb5ef  6689b9c0110000       mov word ptr [ecx + 0x11c0], di
// 005bb5f6  8381b811000001       add dword ptr [ecx + 0x11b8], 1
// 005bb5fd  5f                   pop edi
// 005bb5fe  5e                   pop esi
// 005bb5ff  b800000000           mov eax, 0
// 005bb604  1181bc110000         adc dword ptr [ecx + 0x11bc], eax
// 005bb60a  83b9b811000005       cmp dword ptr [ecx + 0x11b8], 5
// 005bb611  5d                   pop ebp
// 005bb612  5b                   pop ebx
// 005bb613  7514                 jne 0x5bb629
// 005bb615  3981bc110000         cmp dword ptr [ecx + 0x11bc], eax
// 005bb61b  750c                 jne 0x5bb629
// 005bb61d  8981b8110000         mov dword ptr [ecx + 0x11b8], eax
// 005bb623  8981bc110000         mov dword ptr [ecx + 0x11bc], eax
// 005bb629  c21400               ret 0x14
// copied from an identical function in another client (function ?OnConnectedPong@RakPeer@RakNet@@IAEX_K0PAURemoteSystemStruct@12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp