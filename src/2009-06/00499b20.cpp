// from server: 100% by auto
// roc 2009-06 00499b20  unit: Ogre::RbxArchive  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00499b20
//
// 00499b20  6aff                 push -1
// 00499b22  68046b8500           push 0x856b04
// 00499b27  64a100000000         mov eax, dword ptr fs:[0]
// 00499b2d  50                   push eax
// 00499b2e  64892500000000       mov dword ptr fs:[0], esp
// 00499b35  83ec08               sub esp, 8
// 00499b38  53                   push ebx
// 00499b39  56                   push esi
// 00499b3a  57                   push edi
// 00499b3b  33db                 xor ebx, ebx
// 00499b3d  6a18                 push 0x18
// 00499b3f  8bf9                 mov edi, ecx
// 00499b41  895c2420             mov dword ptr [esp + 0x20], ebx
// 00499b45  895c2410             mov dword ptr [esp + 0x10], ebx
// 00499b49  e8eaee2700           call 0x718a38
// 00499b4e  83c404               add esp, 4
// 00499b51  89442410             mov dword ptr [esp + 0x10], eax
// 00499b55  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00499b5d  3bc3                 cmp eax, ebx
// 00499b5f  7409                 je 0x499b6a
// 00499b61  8bc8                 mov ecx, eax
// 00499b63  e8a80a1c00           call 0x65a610
// 00499b68  eb02                 jmp 0x499b6c
// 00499b6a  33c0                 xor eax, eax
// 00499b6c  8b742424             mov esi, dword ptr [esp + 0x24]
// 00499b70  6a04                 push 4
// 00499b72  885c2420             mov byte ptr [esp + 0x20], bl
// 00499b76  c706e0fb8b00         mov dword ptr [esi], 0x8bfbe0
// 00499b7c  894604               mov dword ptr [esi + 4], eax
// 00499b7f  e8b4ee2700           call 0x718a38
// 00499b84  83c404               add esp, 4
// 00499b87  3bc3                 cmp eax, ebx
// 00499b89  7408                 je 0x499b93
// 00499b8b  c70001000000         mov dword ptr [eax], 1
// 00499b91  eb02                 jmp 0x499b95
// 00499b93  33c0                 xor eax, eax
// 00499b95  894608               mov dword ptr [esi + 8], eax
// 00499b98  8b4604               mov eax, dword ptr [esi + 4]
// 00499b9b  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00499b9f  8b542428             mov edx, dword ptr [esp + 0x28]
// 00499ba3  50                   push eax
// 00499ba4  8b442434             mov eax, dword ptr [esp + 0x34]
// 00499ba8  53                   push ebx
// 00499ba9  50                   push eax
// 00499baa  51                   push ecx
// 00499bab  52                   push edx
// 00499bac  8bcf                 mov ecx, edi
// 00499bae  895c2430             mov dword ptr [esp + 0x30], ebx
// 00499bb2  c744242001000000     mov dword ptr [esp + 0x20], 1
// 00499bba  e8c1f7ffff           call 0x499380
// 00499bbf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00499bc3  5f                   pop edi
// 00499bc4  8bc6                 mov eax, esi
// 00499bc6  5e                   pop esi
// 00499bc7  5b                   pop ebx
// 00499bc8  64890d00000000       mov dword ptr fs:[0], ecx
// 00499bcf  83c414               add esp, 0x14
// 00499bd2  c21000               ret 0x10
// library ogre-1.4.9/OgreFileSystem.cpp (function ?findFileInfo@FileSystemArchive@Ogre@@UAE?AV?$SharedPtr@V?$vector@UFileInfo@Ogre@@V?$allocator@UFileInfo@Ogre@@@std@@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N1@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreFileSystem.cpp
