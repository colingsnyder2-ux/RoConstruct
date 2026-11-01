// from server: 100% by auto
// roc 2010-06 00962fd0  unit: Ogre::RbxSceneUpdater  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00962fd0
//
// 00962fd0  6aff                 push -1
// 00962fd2  68ee219c00           push 0x9c21ee
// 00962fd7  64a100000000         mov eax, dword ptr fs:[0]
// 00962fdd  50                   push eax
// 00962fde  64892500000000       mov dword ptr fs:[0], esp
// 00962fe5  83ec08               sub esp, 8
// 00962fe8  53                   push ebx
// 00962fe9  55                   push ebp
// 00962fea  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00962fee  8a4504               mov al, byte ptr [ebp + 4]
// 00962ff1  56                   push esi
// 00962ff2  8bf1                 mov esi, ecx
// 00962ff4  57                   push edi
// 00962ff5  8d4c2428             lea ecx, [esp + 0x28]
// 00962ff9  51                   push ecx
// 00962ffa  8d4e08               lea ecx, [esi + 8]
// 00962ffd  89742418             mov dword ptr [esp + 0x18], esi
// 00963001  884604               mov byte ptr [esi + 4], al
// 00963004  e8a7edffff           call 0x961db0
// 00963009  33db                 xor ebx, ebx
// 0096300b  6a04                 push 4
// 0096300d  895c2424             mov dword ptr [esp + 0x24], ebx
// 00963011  8d7e24               lea edi, [esi + 0x24]
// 00963014  e88749e4ff           call 0x7a79a0
// 00963019  83c404               add esp, 4
// 0096301c  3bc3                 cmp eax, ebx
// 0096301e  7404                 je 0x963024
// 00963020  8938                 mov dword ptr [eax], edi
// 00963022  eb02                 jmp 0x963026
// 00963024  33c0                 xor eax, eax
// 00963026  8907                 mov dword ptr [edi], eax
// 00963028  895f0c               mov dword ptr [edi + 0xc], ebx
// 0096302b  895f10               mov dword ptr [edi + 0x10], ebx
// 0096302e  895f14               mov dword ptr [edi + 0x14], ebx
// 00963031  55                   push ebp
// 00963032  8bce                 mov ecx, esi
// 00963034  c644242402           mov byte ptr [esp + 0x24], 2
// 00963039  e8b2faffff           call 0x962af0
// 0096303e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00963042  5f                   pop edi
// 00963043  8bc6                 mov eax, esi
// 00963045  5e                   pop esi
// 00963046  5d                   pop ebp
// 00963047  5b                   pop ebx
// 00963048  64890d00000000       mov dword ptr fs:[0], ecx
// 0096304f  83c414               add esp, 0x14
// 00963052  c20400               ret 4
// library ogre-1.7.0/OgreResourceManager.cpp (function ??0?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@V?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@$0A@@stdext@@@stdext@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
