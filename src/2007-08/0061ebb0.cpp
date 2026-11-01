// from server: 100% by auto
// roc 2007-08 0061ebb0  unit: RBX::ScoreHud  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061ebb0
//
// 0061ebb0  55                   push ebp
// 0061ebb1  8bec                 mov ebp, esp
// 0061ebb3  6aff                 push -1
// 0061ebb5  68a1ca7500           push 0x75caa1
// 0061ebba  64a100000000         mov eax, dword ptr fs:[0]
// 0061ebc0  50                   push eax
// 0061ebc1  64892500000000       mov dword ptr fs:[0], esp
// 0061ebc8  83ec0c               sub esp, 0xc
// 0061ebcb  53                   push ebx
// 0061ebcc  56                   push esi
// 0061ebcd  57                   push edi
// 0061ebce  8965f0               mov dword ptr [ebp - 0x10], esp
// 0061ebd1  6a38                 push 0x38
// 0061ebd3  e81e130100           call 0x62fef6
// 0061ebd8  8bf0                 mov esi, eax
// 0061ebda  83c404               add esp, 4
// 0061ebdd  8975ec               mov dword ptr [ebp - 0x14], esi
// 0061ebe0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0061ebe7  8975e8               mov dword ptr [ebp - 0x18], esi
// 0061ebea  85f6                 test esi, esi
// 0061ebec  c645fc01             mov byte ptr [ebp - 4], 1
// 0061ebf0  7427                 je 0x61ec19
// 0061ebf2  8b4508               mov eax, dword ptr [ebp + 8]
// 0061ebf5  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0061ebf8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0061ebfb  8906                 mov dword ptr [esi], eax
// 0061ebfd  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0061ec00  894e04               mov dword ptr [esi + 4], ecx
// 0061ec03  50                   push eax
// 0061ec04  8d4e0c               lea ecx, [esi + 0xc]
// 0061ec07  895608               mov dword ptr [esi + 8], edx
// 0061ec0a  e871f6ffff           call 0x61e280
// 0061ec0f  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 0061ec12  884e34               mov byte ptr [esi + 0x34], cl
// 0061ec15  c6463500             mov byte ptr [esi + 0x35], 0
// 0061ec19  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0061ec1c  5f                   pop edi
// 0061ec1d  8bc6                 mov eax, esi
// 0061ec1f  5e                   pop esi
// 0061ec20  64890d00000000       mov dword ptr fs:[0], ecx
// 0061ec27  5b                   pop ebx
// 0061ec28  8be5                 mov esp, ebp
// 0061ec2a  5d                   pop ebp
// 0061ec2b  c21400               ret 0x14
// library ogre-1.6.4/OgreParticle.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$list@PAVParticleEmitter@Ogre@@V?$allocator@PAVParticleEmitter@Ogre@@@std@@@2@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$list@PAVParticleEmitter@Ogre@@V?$allocator@PAVParticleEmitter@Ogre@@@std@@@2@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$list@PAVParticleEmitter@Ogre@@V?$allocator@PAVParticleEmitter@Ogre@@@std@@@2@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$list@PAVParticleEmitter@Ogre@@V?$allocator@PAVParticleEmitter@Ogre@@@std@@@2@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$list@PAVParticleEmitter@Ogre@@V?$allocator@PAVParticleEmitter@Ogre@@@std@@@2@@2@D@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreParticle.cpp
