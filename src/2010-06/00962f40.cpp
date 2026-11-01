// from server: 100% by auto
// roc 2010-06 00962f40  unit: Ogre::RbxSceneUpdater  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00962f40
//
// 00962f40  6aff                 push -1
// 00962f42  68be219c00           push 0x9c21be
// 00962f47  64a100000000         mov eax, dword ptr fs:[0]
// 00962f4d  50                   push eax
// 00962f4e  64892500000000       mov dword ptr fs:[0], esp
// 00962f55  83ec08               sub esp, 8
// 00962f58  53                   push ebx
// 00962f59  55                   push ebp
// 00962f5a  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00962f5e  8a4504               mov al, byte ptr [ebp + 4]
// 00962f61  56                   push esi
// 00962f62  8bf1                 mov esi, ecx
// 00962f64  57                   push edi
// 00962f65  8d4c2428             lea ecx, [esp + 0x28]
// 00962f69  51                   push ecx
// 00962f6a  8d4e08               lea ecx, [esi + 8]
// 00962f6d  89742418             mov dword ptr [esp + 0x18], esi
// 00962f71  884604               mov byte ptr [esi + 4], al
// 00962f74  e8d7b7f9ff           call 0x8fe750
// 00962f79  33db                 xor ebx, ebx
// 00962f7b  6a04                 push 4
// 00962f7d  895c2424             mov dword ptr [esp + 0x24], ebx
// 00962f81  8d7e24               lea edi, [esi + 0x24]
// 00962f84  e8174ae4ff           call 0x7a79a0
// 00962f89  83c404               add esp, 4
// 00962f8c  3bc3                 cmp eax, ebx
// 00962f8e  7404                 je 0x962f94
// 00962f90  8938                 mov dword ptr [eax], edi
// 00962f92  eb02                 jmp 0x962f96
// 00962f94  33c0                 xor eax, eax
// 00962f96  8907                 mov dword ptr [edi], eax
// 00962f98  895f0c               mov dword ptr [edi + 0xc], ebx
// 00962f9b  895f10               mov dword ptr [edi + 0x10], ebx
// 00962f9e  895f14               mov dword ptr [edi + 0x14], ebx
// 00962fa1  55                   push ebp
// 00962fa2  8bce                 mov ecx, esi
// 00962fa4  c644242402           mov byte ptr [esp + 0x24], 2
// 00962fa9  e8f2f8ffff           call 0x9628a0
// 00962fae  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00962fb2  5f                   pop edi
// 00962fb3  8bc6                 mov eax, esi
// 00962fb5  5e                   pop esi
// 00962fb6  5d                   pop ebp
// 00962fb7  5b                   pop ebx
// 00962fb8  64890d00000000       mov dword ptr fs:[0], ecx
// 00962fbf  83c414               add esp, 0x14
// 00962fc2  c20400               ret 4
// library ogre-1.7.0/OgreResourceManager.cpp (function ??0?$_Hash@V?$_Hmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@V?$hash_compare@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@stdext@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@2@$0A@@stdext@@@stdext@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
