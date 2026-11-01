// from server: 100% by auto
// roc 2009-12 004b36c0  unit: Ogre::VGpuProgramParameters::?$SharedPtr  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b36c0
//
// 004b36c0  53                   push ebx
// 004b36c1  8b1df0bc9800         mov ebx, dword ptr [0x98bcf0]
// 004b36c7  56                   push esi
// 004b36c8  8bf1                 mov esi, ecx
// 004b36ca  8b460c               mov eax, dword ptr [esi + 0xc]
// 004b36cd  83e800               sub eax, 0
// 004b36d0  7441                 je 0x4b3713
// 004b36d2  83e801               sub eax, 1
// 004b36d5  741a                 je 0x4b36f1
// 004b36d7  83e801               sub eax, 1
// 004b36da  754e                 jne 0x4b372a
// 004b36dc  8b4604               mov eax, dword ptr [esi + 4]
// 004b36df  50                   push eax
// 004b36e0  ffd3                 call ebx
// 004b36e2  8b5608               mov edx, dword ptr [esi + 8]
// 004b36e5  83c404               add esp, 4
// 004b36e8  52                   push edx
// 004b36e9  ffd3                 call ebx
// 004b36eb  83c404               add esp, 4
// 004b36ee  5e                   pop esi
// 004b36ef  5b                   pop ebx
// 004b36f0  c3                   ret 
// 004b36f1  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b36f4  85c9                 test ecx, ecx
// 004b36f6  7432                 je 0x4b372a
// 004b36f8  ff1550c29800         call dword ptr [0x98c250]
// 004b36fe  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b3701  51                   push ecx
// 004b3702  ffd3                 call ebx
// 004b3704  8b5608               mov edx, dword ptr [esi + 8]
// 004b3707  83c404               add esp, 4
// 004b370a  52                   push edx
// 004b370b  ffd3                 call ebx
// 004b370d  83c404               add esp, 4
// 004b3710  5e                   pop esi
// 004b3711  5b                   pop ebx
// 004b3712  c3                   ret 
// 004b3713  57                   push edi
// 004b3714  8b7e04               mov edi, dword ptr [esi + 4]
// 004b3717  85ff                 test edi, edi
// 004b3719  740e                 je 0x4b3729
// 004b371b  8bcf                 mov ecx, edi
// 004b371d  ff1550c29800         call dword ptr [0x98c250]
// 004b3723  57                   push edi
// 004b3724  ffd3                 call ebx
// 004b3726  83c404               add esp, 4
// 004b3729  5f                   pop edi
// 004b372a  8b5608               mov edx, dword ptr [esi + 8]
// 004b372d  52                   push edx
// 004b372e  ffd3                 call ebx
// 004b3730  83c404               add esp, 4
// 004b3733  5e                   pop esi
// 004b3734  5b                   pop ebx
// 004b3735  c3                   ret 
// library ogre-1.7.0/OgreGpuProgramUsage.cpp (function ?destroy@?$SharedPtr@VGpuProgramParameters@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreGpuProgramUsage.cpp
