// from server: 100% by auto
// roc 2009-12 0057e720  unit: Ogre::RbxSceneUpdater  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057e720
//
// 0057e720  6aff                 push -1
// 0057e722  68cec39300           push 0x93c3ce
// 0057e727  64a100000000         mov eax, dword ptr fs:[0]
// 0057e72d  50                   push eax
// 0057e72e  64892500000000       mov dword ptr fs:[0], esp
// 0057e735  83ec08               sub esp, 8
// 0057e738  53                   push ebx
// 0057e739  55                   push ebp
// 0057e73a  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0057e73e  8a4504               mov al, byte ptr [ebp + 4]
// 0057e741  56                   push esi
// 0057e742  8bf1                 mov esi, ecx
// 0057e744  57                   push edi
// 0057e745  8d4c2428             lea ecx, [esp + 0x28]
// 0057e749  51                   push ecx
// 0057e74a  8d4e08               lea ecx, [esi + 8]
// 0057e74d  89742418             mov dword ptr [esp + 0x18], esi
// 0057e751  884604               mov byte ptr [esi + 4], al
// 0057e754  e887ecffff           call 0x57d3e0
// 0057e759  33db                 xor ebx, ebx
// 0057e75b  6a04                 push 4
// 0057e75d  895c2424             mov dword ptr [esp + 0x24], ebx
// 0057e761  8d7e24               lea edi, [esi + 0x24]
// 0057e764  e8f7502700           call 0x7f3860
// 0057e769  83c404               add esp, 4
// 0057e76c  3bc3                 cmp eax, ebx
// 0057e76e  7404                 je 0x57e774
// 0057e770  8938                 mov dword ptr [eax], edi
// 0057e772  eb02                 jmp 0x57e776
// 0057e774  33c0                 xor eax, eax
// 0057e776  8907                 mov dword ptr [edi], eax
// 0057e778  895f0c               mov dword ptr [edi + 0xc], ebx
// 0057e77b  895f10               mov dword ptr [edi + 0x10], ebx
// 0057e77e  895f14               mov dword ptr [edi + 0x14], ebx
// 0057e781  55                   push ebp
// 0057e782  8bce                 mov ecx, esi
// 0057e784  c644242402           mov byte ptr [esp + 0x24], 2
// 0057e789  e8c2f9ffff           call 0x57e150
// 0057e78e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057e792  5f                   pop edi
// 0057e793  8bc6                 mov eax, esi
// 0057e795  5e                   pop esi
// 0057e796  5d                   pop ebp
// 0057e797  5b                   pop ebx
// 0057e798  64890d00000000       mov dword ptr fs:[0], ecx
// 0057e79f  83c414               add esp, 0x14
// 0057e7a2  c20400               ret 4
// library ogre-1.7.0/OgreResourceManager.cpp (function ??0?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@V?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@$0A@@stdext@@@stdext@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
