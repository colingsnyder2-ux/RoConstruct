// from server: 100% by auto
// roc 2011-06 0093d830  unit: Ogre::VGpuProgramParameters::?$SharedPtr  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0093d830
//
// 0093d830  53                   push ebx
// 0093d831  8b1d1c19a400         mov ebx, dword ptr [0xa4191c]
// 0093d837  56                   push esi
// 0093d838  8bf1                 mov esi, ecx
// 0093d83a  8b460c               mov eax, dword ptr [esi + 0xc]
// 0093d83d  83e800               sub eax, 0
// 0093d840  7441                 je 0x93d883
// 0093d842  83e801               sub eax, 1
// 0093d845  741a                 je 0x93d861
// 0093d847  83e801               sub eax, 1
// 0093d84a  754e                 jne 0x93d89a
// 0093d84c  8b4604               mov eax, dword ptr [esi + 4]
// 0093d84f  50                   push eax
// 0093d850  ffd3                 call ebx
// 0093d852  8b5608               mov edx, dword ptr [esi + 8]
// 0093d855  83c404               add esp, 4
// 0093d858  52                   push edx
// 0093d859  ffd3                 call ebx
// 0093d85b  83c404               add esp, 4
// 0093d85e  5e                   pop esi
// 0093d85f  5b                   pop ebx
// 0093d860  c3                   ret 
// 0093d861  8b4e04               mov ecx, dword ptr [esi + 4]
// 0093d864  85c9                 test ecx, ecx
// 0093d866  7432                 je 0x93d89a
// 0093d868  ff15240fa400         call dword ptr [0xa40f24]
// 0093d86e  8b4e04               mov ecx, dword ptr [esi + 4]
// 0093d871  51                   push ecx
// 0093d872  ffd3                 call ebx
// 0093d874  8b5608               mov edx, dword ptr [esi + 8]
// 0093d877  83c404               add esp, 4
// 0093d87a  52                   push edx
// 0093d87b  ffd3                 call ebx
// 0093d87d  83c404               add esp, 4
// 0093d880  5e                   pop esi
// 0093d881  5b                   pop ebx
// 0093d882  c3                   ret 
// 0093d883  57                   push edi
// 0093d884  8b7e04               mov edi, dword ptr [esi + 4]
// 0093d887  85ff                 test edi, edi
// 0093d889  740e                 je 0x93d899
// 0093d88b  8bcf                 mov ecx, edi
// 0093d88d  ff15240fa400         call dword ptr [0xa40f24]
// 0093d893  57                   push edi
// 0093d894  ffd3                 call ebx
// 0093d896  83c404               add esp, 4
// 0093d899  5f                   pop edi
// 0093d89a  8b5608               mov edx, dword ptr [esi + 8]
// 0093d89d  52                   push edx
// 0093d89e  ffd3                 call ebx
// 0093d8a0  83c404               add esp, 4
// 0093d8a3  5e                   pop esi
// 0093d8a4  5b                   pop ebx
// 0093d8a5  c3                   ret 
// library ogre-1.7.0/OgreGpuProgramUsage.cpp (function ?destroy@?$SharedPtr@VGpuProgramParameters@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreGpuProgramUsage.cpp
