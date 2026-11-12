// from server: 100% by auto
// roc 2008-06 004d1140  unit: RBX::Network::PhysicsSender  size: 403 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d1140
//
// 004d1140  8b442410             mov eax, dword ptr [esp + 0x10]
// 004d1144  83f804               cmp eax, 4
// 004d1147  53                   push ebx
// 004d1148  55                   push ebp
// 004d1149  57                   push edi
// 004d114a  8be9                 mov ebp, ecx
// 004d114c  7f04                 jg 0x4d1152
// 004d114e  85c0                 test eax, eax
// 004d1150  7d08                 jge 0x4d115a
// 004d1152  c744241c02000000     mov dword ptr [esp + 0x1c], 2
// 004d115a  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004d115e  83fb04               cmp ebx, 4
// 004d1161  7f04                 jg 0x4d1167
// 004d1163  85db                 test ebx, ebx
// 004d1165  7d05                 jge 0x4d116c
// 004d1167  bb01000000           mov ebx, 1
// 004d116c  807c242020           cmp byte ptr [esp + 0x20], 0x20
// 004d1171  7205                 jb 0x4d1178
// 004d1173  c644242000           mov byte ptr [esp + 0x20], 0
// 004d1178  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004d117c  8d4707               lea eax, [edi + 7]
// 004d117f  c1f803               sar eax, 3
// 004d1182  89442418             mov dword ptr [esp + 0x18], eax
// 004d1186  85ff                 test edi, edi
// 004d1188  7508                 jne 0x4d1192
// 004d118a  5f                   pop edi
// 004d118b  5d                   pop ebp
// 004d118c  32c0                 xor al, al
// 004d118e  5b                   pop ebx
// 004d118f  c22400               ret 0x24
// 004d1192  56                   push esi
// 004d1193  8d8db0070000         lea ecx, [ebp + 0x7b0]
// 004d1199  e862e7ffff           call 0x4cf900
// 004d119e  807c242800           cmp byte ptr [esp + 0x28], 0
// 004d11a3  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004d11a7  8bf0                 mov esi, eax
// 004d11a9  8b442430             mov eax, dword ptr [esp + 0x30]
// 004d11ad  894628               mov dword ptr [esi + 0x28], eax
// 004d11b0  89742418             mov dword ptr [esp + 0x18], esi
// 004d11b4  894e2c               mov dword ptr [esi + 0x2c], ecx
// 004d11b7  7422                 je 0x4d11db
// 004d11b9  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004d11bd  52                   push edx
// 004d11be  e85df71c00           call 0x6a0920
// 004d11c3  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004d11c7  8b542418             mov edx, dword ptr [esp + 0x18]
// 004d11cb  51                   push ecx
// 004d11cc  52                   push edx
// 004d11cd  50                   push eax
// 004d11ce  89463c               mov dword ptr [esi + 0x3c], eax
// 004d11d1  e80a061d00           call 0x6a17e0
// 004d11d6  83c410               add esp, 0x10
// 004d11d9  eb07                 jmp 0x4d11e2
// 004d11db  8b442414             mov eax, dword ptr [esp + 0x14]
// 004d11df  89463c               mov dword ptr [esi + 0x3c], eax
// 004d11e2  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004d11e6  897e38               mov dword ptr [esi + 0x38], edi
// 004d11e9  33c0                 xor eax, eax
// 004d11eb  894630               mov dword ptr [esi + 0x30], eax
// 004d11ee  894634               mov dword ptr [esi + 0x34], eax
// 004d11f1  c706ffffffff         mov dword ptr [esi], 0xffffffff
// 004d11f7  884604               mov byte ptr [esi + 4], al
// 004d11fa  895e0c               mov dword ptr [esi + 0xc], ebx
// 004d11fd  894e10               mov dword ptr [esi + 0x10], ecx
// 004d1200  894624               mov dword ptr [esi + 0x24], eax
// 004d1203  bb01000000           mov ebx, 1
// 004d1208  b823000000           mov eax, 0x23
// 004d120d  395e10               cmp dword ptr [esi + 0x10], ebx
// 004d1210  740d                 je 0x4d121f
// 004d1212  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004d1215  83f904               cmp ecx, 4
// 004d1218  7405                 je 0x4d121f
// 004d121a  83f903               cmp ecx, 3
// 004d121d  7505                 jne 0x4d1224
// 004d121f  b848000000           mov eax, 0x48
// 004d1224  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004d1228  03c3                 add eax, ebx
// 004d122a  83c017               add eax, 0x17
// 004d122d  c1f803               sar eax, 3
// 004d1230  2bf8                 sub edi, eax
// 004d1232  8d8d28050000         lea ecx, [ebp + 0x528]
// 004d1238  83ef1c               sub edi, 0x1c
// 004d123b  e850470000           call 0x4d5990
// 004d1240  84c0                 test al, al
// 004d1242  7403                 je 0x4d1247
// 004d1244  83ef10               sub edi, 0x10
// 004d1247  397c241c             cmp dword ptr [esp + 0x1c], edi
// 004d124b  0f9fc1               setg cl
// 004d124e  84c9                 test cl, cl
// 004d1250  7408                 je 0x4d125a
// 004d1252  019d48040000         add dword ptr [ebp + 0x448], ebx
// 004d1258  eb06                 jmp 0x4d1260
// 004d125a  019d44040000         add dword ptr [ebp + 0x444], ebx
// 004d1260  8b4610               mov eax, dword ptr [esi + 0x10]
// 004d1263  83f804               cmp eax, 4
// 004d1266  741c                 je 0x4d1284
// 004d1268  3bc3                 cmp eax, ebx
// 004d126a  7418                 je 0x4d1284
// 004d126c  83f803               cmp eax, 3
// 004d126f  752b                 jne 0x4d129c
// 004d1271  8a442424             mov al, byte ptr [esp + 0x24]
// 004d1275  0fb6d0               movzx edx, al
// 004d1278  884614               mov byte ptr [esi + 0x14], al
// 004d127b  8d8495d4010000       lea eax, [ebp + edx*4 + 0x1d4]
// 004d1282  eb11                 jmp 0x4d1295
// 004d1284  8a442424             mov al, byte ptr [esp + 0x24]
// 004d1288  884614               mov byte ptr [esi + 0x14], al
// 004d128b  0fb6c0               movzx eax, al
// 004d128e  8d848554020000       lea eax, [ebp + eax*4 + 0x254]
// 004d1295  8b10                 mov edx, dword ptr [eax]
// 004d1297  895618               mov dword ptr [esi + 0x18], edx
// 004d129a  0118                 add dword ptr [eax], ebx
// 004d129c  84c9                 test cl, cl
// 004d129e  7416                 je 0x4d12b6
// 004d12a0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004d12a4  50                   push eax
// 004d12a5  56                   push esi
// 004d12a6  8bcd                 mov ecx, ebp
// 004d12a8  e823f5ffff           call 0x4d07d0
// 004d12ad  5e                   pop esi
// 004d12ae  5f                   pop edi
// 004d12af  5d                   pop ebp
// 004d12b0  8ac3                 mov al, bl
// 004d12b2  5b                   pop ebx
// 004d12b3  c22400               ret 0x24
// 004d12b6  8b560c               mov edx, dword ptr [esi + 0xc]
// 004d12b9  8d4c2418             lea ecx, [esp + 0x18]
// 004d12bd  c1e204               shl edx, 4
// 004d12c0  51                   push ecx
// 004d12c1  8d4c2a64             lea ecx, [edx + ebp + 0x64]
// 004d12c5  e816dbffff           call 0x4cede0
// 004d12ca  5e                   pop esi
// 004d12cb  5f                   pop edi
// 004d12cc  5d                   pop ebp
// 004d12cd  8ac3                 mov al, bl
// 004d12cf  5b                   pop ebx
// 004d12d0  c22400               ret 0x24
// library openrbx-raknet/ReliabilityLayer.cpp (function ?Send@ReliabilityLayer@@QAE_NPADHW4PacketPriority@@W4PacketReliability@@E_NH_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet ReliabilityLayer.cpp
