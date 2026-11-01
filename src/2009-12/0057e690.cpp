// from server: 100% by auto
// roc 2009-12 0057e690  unit: Ogre::RbxSceneUpdater  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057e690
//
// 0057e690  6aff                 push -1
// 0057e692  689ec39300           push 0x93c39e
// 0057e697  64a100000000         mov eax, dword ptr fs:[0]
// 0057e69d  50                   push eax
// 0057e69e  64892500000000       mov dword ptr fs:[0], esp
// 0057e6a5  83ec08               sub esp, 8
// 0057e6a8  53                   push ebx
// 0057e6a9  55                   push ebp
// 0057e6aa  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0057e6ae  8a4504               mov al, byte ptr [ebp + 4]
// 0057e6b1  56                   push esi
// 0057e6b2  8bf1                 mov esi, ecx
// 0057e6b4  57                   push edi
// 0057e6b5  8d4c2428             lea ecx, [esp + 0x28]
// 0057e6b9  51                   push ecx
// 0057e6ba  8d4e08               lea ecx, [esi + 8]
// 0057e6bd  89742418             mov dword ptr [esp + 0x18], esi
// 0057e6c1  884604               mov byte ptr [esi + 4], al
// 0057e6c4  e8e7c7f2ff           call 0x4aaeb0
// 0057e6c9  33db                 xor ebx, ebx
// 0057e6cb  6a04                 push 4
// 0057e6cd  895c2424             mov dword ptr [esp + 0x24], ebx
// 0057e6d1  8d7e24               lea edi, [esi + 0x24]
// 0057e6d4  e887512700           call 0x7f3860
// 0057e6d9  83c404               add esp, 4
// 0057e6dc  3bc3                 cmp eax, ebx
// 0057e6de  7404                 je 0x57e6e4
// 0057e6e0  8938                 mov dword ptr [eax], edi
// 0057e6e2  eb02                 jmp 0x57e6e6
// 0057e6e4  33c0                 xor eax, eax
// 0057e6e6  8907                 mov dword ptr [edi], eax
// 0057e6e8  895f0c               mov dword ptr [edi + 0xc], ebx
// 0057e6eb  895f10               mov dword ptr [edi + 0x10], ebx
// 0057e6ee  895f14               mov dword ptr [edi + 0x14], ebx
// 0057e6f1  55                   push ebp
// 0057e6f2  8bce                 mov ecx, esi
// 0057e6f4  c644242402           mov byte ptr [esp + 0x24], 2
// 0057e6f9  e802f8ffff           call 0x57df00
// 0057e6fe  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0057e702  5f                   pop edi
// 0057e703  8bc6                 mov eax, esi
// 0057e705  5e                   pop esi
// 0057e706  5d                   pop ebp
// 0057e707  5b                   pop ebx
// 0057e708  64890d00000000       mov dword ptr fs:[0], ecx
// 0057e70f  83c414               add esp, 0x14
// 0057e712  c20400               ret 4
// library ogre-1.7.0/OgreResourceManager.cpp (function ??0?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@V?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@$0A@@stdext@@@stdext@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
