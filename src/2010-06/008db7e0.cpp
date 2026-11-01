// from server: 100% by auto
// roc 2010-06 008db7e0  unit: Ogre::VGpuProgramParameters::?$SharedPtr  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008db7e0
//
// 008db7e0  53                   push ebx
// 008db7e1  8b1df0b89e00         mov ebx, dword ptr [0x9eb8f0]
// 008db7e7  56                   push esi
// 008db7e8  8bf1                 mov esi, ecx
// 008db7ea  8b460c               mov eax, dword ptr [esi + 0xc]
// 008db7ed  83e800               sub eax, 0
// 008db7f0  7441                 je 0x8db833
// 008db7f2  83e801               sub eax, 1
// 008db7f5  741a                 je 0x8db811
// 008db7f7  83e801               sub eax, 1
// 008db7fa  754e                 jne 0x8db84a
// 008db7fc  8b4604               mov eax, dword ptr [esi + 4]
// 008db7ff  50                   push eax
// 008db800  ffd3                 call ebx
// 008db802  8b5608               mov edx, dword ptr [esi + 8]
// 008db805  83c404               add esp, 4
// 008db808  52                   push edx
// 008db809  ffd3                 call ebx
// 008db80b  83c404               add esp, 4
// 008db80e  5e                   pop esi
// 008db80f  5b                   pop ebx
// 008db810  c3                   ret 
// 008db811  8b4e04               mov ecx, dword ptr [esi + 4]
// 008db814  85c9                 test ecx, ecx
// 008db816  7432                 je 0x8db84a
// 008db818  ff1568b49e00         call dword ptr [0x9eb468]
// 008db81e  8b4e04               mov ecx, dword ptr [esi + 4]
// 008db821  51                   push ecx
// 008db822  ffd3                 call ebx
// 008db824  8b5608               mov edx, dword ptr [esi + 8]
// 008db827  83c404               add esp, 4
// 008db82a  52                   push edx
// 008db82b  ffd3                 call ebx
// 008db82d  83c404               add esp, 4
// 008db830  5e                   pop esi
// 008db831  5b                   pop ebx
// 008db832  c3                   ret 
// 008db833  57                   push edi
// 008db834  8b7e04               mov edi, dword ptr [esi + 4]
// 008db837  85ff                 test edi, edi
// 008db839  740e                 je 0x8db849
// 008db83b  8bcf                 mov ecx, edi
// 008db83d  ff1568b49e00         call dword ptr [0x9eb468]
// 008db843  57                   push edi
// 008db844  ffd3                 call ebx
// 008db846  83c404               add esp, 4
// 008db849  5f                   pop edi
// 008db84a  8b5608               mov edx, dword ptr [esi + 8]
// 008db84d  52                   push edx
// 008db84e  ffd3                 call ebx
// 008db850  83c404               add esp, 4
// 008db853  5e                   pop esi
// 008db854  5b                   pop ebx
// 008db855  c3                   ret 
// library ogre-1.7.0/OgreGpuProgramUsage.cpp (function ?destroy@?$SharedPtr@VGpuProgramParameters@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreGpuProgramUsage.cpp
