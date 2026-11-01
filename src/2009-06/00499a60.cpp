// from server: 100% by auto
// roc 2009-06 00499a60  unit: Ogre::RbxArchive  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00499a60
//
// 00499a60  6aff                 push -1
// 00499a62  68d46a8500           push 0x856ad4
// 00499a67  64a100000000         mov eax, dword ptr fs:[0]
// 00499a6d  50                   push eax
// 00499a6e  64892500000000       mov dword ptr fs:[0], esp
// 00499a75  83ec08               sub esp, 8
// 00499a78  53                   push ebx
// 00499a79  56                   push esi
// 00499a7a  57                   push edi
// 00499a7b  33db                 xor ebx, ebx
// 00499a7d  6a18                 push 0x18
// 00499a7f  8bf9                 mov edi, ecx
// 00499a81  895c2420             mov dword ptr [esp + 0x20], ebx
// 00499a85  895c2410             mov dword ptr [esp + 0x10], ebx
// 00499a89  e8aaef2700           call 0x718a38
// 00499a8e  83c404               add esp, 4
// 00499a91  89442410             mov dword ptr [esp + 0x10], eax
// 00499a95  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00499a9d  3bc3                 cmp eax, ebx
// 00499a9f  7409                 je 0x499aaa
// 00499aa1  8bc8                 mov ecx, eax
// 00499aa3  e8680b1c00           call 0x65a610
// 00499aa8  eb02                 jmp 0x499aac
// 00499aaa  33c0                 xor eax, eax
// 00499aac  8b742424             mov esi, dword ptr [esp + 0x24]
// 00499ab0  6a04                 push 4
// 00499ab2  885c2420             mov byte ptr [esp + 0x20], bl
// 00499ab6  c706d0fb8b00         mov dword ptr [esi], 0x8bfbd0
// 00499abc  894604               mov dword ptr [esi + 4], eax
// 00499abf  e874ef2700           call 0x718a38
// 00499ac4  83c404               add esp, 4
// 00499ac7  3bc3                 cmp eax, ebx
// 00499ac9  7408                 je 0x499ad3
// 00499acb  c70001000000         mov dword ptr [eax], 1
// 00499ad1  eb02                 jmp 0x499ad5
// 00499ad3  33c0                 xor eax, eax
// 00499ad5  894608               mov dword ptr [esi + 8], eax
// 00499ad8  8b4604               mov eax, dword ptr [esi + 4]
// 00499adb  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00499adf  8b542428             mov edx, dword ptr [esp + 0x28]
// 00499ae3  53                   push ebx
// 00499ae4  50                   push eax
// 00499ae5  8b442438             mov eax, dword ptr [esp + 0x38]
// 00499ae9  50                   push eax
// 00499aea  51                   push ecx
// 00499aeb  52                   push edx
// 00499aec  8bcf                 mov ecx, edi
// 00499aee  895c2430             mov dword ptr [esp + 0x30], ebx
// 00499af2  c744242001000000     mov dword ptr [esp + 0x20], 1
// 00499afa  e881f8ffff           call 0x499380
// 00499aff  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00499b03  5f                   pop edi
// 00499b04  8bc6                 mov eax, esi
// 00499b06  5e                   pop esi
// 00499b07  5b                   pop ebx
// 00499b08  64890d00000000       mov dword ptr fs:[0], ecx
// 00499b0f  83c414               add esp, 0x14
// 00499b12  c21000               ret 0x10
// library ogre-1.4.9/OgreFileSystem.cpp (function ?find@FileSystemArchive@Ogre@@UAE?AV?$SharedPtr@V?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N1@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreFileSystem.cpp
