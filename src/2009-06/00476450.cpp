// from server: 100% by Yeetserama
// roc 2009-06 00476450  unit: Ogre::RbxMeshLoader  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00476450
//
// 00476450  55                   push ebp
// 00476451  8bec                 mov ebp, esp
// 00476453  6aff                 push -1
// 00476455  6881428500           push 0x854281
// 0047645a  64a100000000         mov eax, dword ptr fs:[0]
// 00476460  50                   push eax
// 00476461  64892500000000       mov dword ptr fs:[0], esp
// 00476468  83ec0c               sub esp, 0xc
// 0047646b  53                   push ebx
// 0047646c  56                   push esi
// 0047646d  57                   push edi
// 0047646e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00476471  6a2c                 push 0x2c
// 00476473  e8c0252a00           call 0x718a38
// 00476478  8bf0                 mov esi, eax
// 0047647a  83c404               add esp, 4
// 0047647d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00476480  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00476487  8975e8               mov dword ptr [ebp - 0x18], esi
// 0047648a  c645fc01             mov byte ptr [ebp - 4], 1
// 0047648e  85f6                 test esi, esi
// 00476490  7428                 je 0x4764ba
// 00476492  8b4508               mov eax, dword ptr [ebp + 8]
// 00476495  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00476498  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0047649b  8906                 mov dword ptr [esi], eax
// 0047649d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004764a0  894e04               mov dword ptr [esi + 4], ecx
// 004764a3  50                   push eax
// 004764a4  8d4e0c               lea ecx, [esi + 0xc]
// 004764a7  895608               mov dword ptr [esi + 8], edx
// 004764aa  ff15b8e48900         call dword ptr [0x89e4b8]
// 004764b0  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 004764b3  884e28               mov byte ptr [esi + 0x28], cl
// 004764b6  c6462900             mov byte ptr [esi + 0x29], 0
// 004764ba  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004764bd  5f                   pop edi
// 004764be  8bc6                 mov eax, esi
// 004764c0  5e                   pop esi
// 004764c1  64890d00000000       mov dword ptr fs:[0], ecx
// 004764c8  5b                   pop ebx
// 004764c9  8be5                 mov esp, ebp
// 004764cb  5d                   pop ebp
// 004764cc  c21400               ret 0x14
// 004764cf  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004764d2  52                   push edx
// 004764d3  e85a252a00           call 0x718a32
// 004764d8  83c404               add esp, 4
// 004764db  6a00                 push 0
// 004764dd  6a00                 push 0
// 004764df  e866352a00           call 0x719a4a
// copied from an identical function in another client (function ?_Buynode@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@2@PAU342@00ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@D@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreBillboardSet.cpp