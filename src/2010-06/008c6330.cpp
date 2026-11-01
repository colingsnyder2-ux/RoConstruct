// from server: 100% by auto
// roc 2010-06 008c6330  unit: Ogre::VResource::?$SharedPtr  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c6330
//
// 008c6330  56                   push esi
// 008c6331  8bf1                 mov esi, ecx
// 008c6333  8b460c               mov eax, dword ptr [esi + 0xc]
// 008c6336  83e800               sub eax, 0
// 008c6339  57                   push edi
// 008c633a  8b3df0b89e00         mov edi, dword ptr [0x9eb8f0]
// 008c6340  7445                 je 0x8c6387
// 008c6342  83e801               sub eax, 1
// 008c6345  741a                 je 0x8c6361
// 008c6347  83e801               sub eax, 1
// 008c634a  754a                 jne 0x8c6396
// 008c634c  8b4604               mov eax, dword ptr [esi + 4]
// 008c634f  50                   push eax
// 008c6350  ffd7                 call edi
// 008c6352  8b4e08               mov ecx, dword ptr [esi + 8]
// 008c6355  83c404               add esp, 4
// 008c6358  51                   push ecx
// 008c6359  ffd7                 call edi
// 008c635b  83c404               add esp, 4
// 008c635e  5f                   pop edi
// 008c635f  5e                   pop esi
// 008c6360  c3                   ret 
// 008c6361  837e0400             cmp dword ptr [esi + 4], 0
// 008c6365  742f                 je 0x8c6396
// 008c6367  8b4e04               mov ecx, dword ptr [esi + 4]
// 008c636a  8b11                 mov edx, dword ptr [ecx]
// 008c636c  8b02                 mov eax, dword ptr [edx]
// 008c636e  6a00                 push 0
// 008c6370  ffd0                 call eax
// 008c6372  8b4e04               mov ecx, dword ptr [esi + 4]
// 008c6375  51                   push ecx
// 008c6376  ffd7                 call edi
// 008c6378  8b4e08               mov ecx, dword ptr [esi + 8]
// 008c637b  83c404               add esp, 4
// 008c637e  51                   push ecx
// 008c637f  ffd7                 call edi
// 008c6381  83c404               add esp, 4
// 008c6384  5f                   pop edi
// 008c6385  5e                   pop esi
// 008c6386  c3                   ret 
// 008c6387  8b4e04               mov ecx, dword ptr [esi + 4]
// 008c638a  85c9                 test ecx, ecx
// 008c638c  7408                 je 0x8c6396
// 008c638e  8b11                 mov edx, dword ptr [ecx]
// 008c6390  8b02                 mov eax, dword ptr [edx]
// 008c6392  6a01                 push 1
// 008c6394  ffd0                 call eax
// 008c6396  8b4e08               mov ecx, dword ptr [esi + 8]
// 008c6399  51                   push ecx
// 008c639a  ffd7                 call edi
// 008c639c  83c404               add esp, 4
// 008c639f  5f                   pop edi
// 008c63a0  5e                   pop esi
// 008c63a1  c3                   ret 
// library ogre-1.7.0/OgreCompositionPass.cpp (function ?destroy@?$SharedPtr@VResource@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositionPass.cpp
