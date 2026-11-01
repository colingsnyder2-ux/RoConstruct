// from server: 100% by auto
// roc 2011-06 00932c70  unit: Ogre::VResource::?$SharedPtr  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00932c70
//
// 00932c70  56                   push esi
// 00932c71  8bf1                 mov esi, ecx
// 00932c73  8b460c               mov eax, dword ptr [esi + 0xc]
// 00932c76  83e800               sub eax, 0
// 00932c79  57                   push edi
// 00932c7a  8b3d1c19a400         mov edi, dword ptr [0xa4191c]
// 00932c80  7445                 je 0x932cc7
// 00932c82  83e801               sub eax, 1
// 00932c85  741a                 je 0x932ca1
// 00932c87  83e801               sub eax, 1
// 00932c8a  754a                 jne 0x932cd6
// 00932c8c  8b4604               mov eax, dword ptr [esi + 4]
// 00932c8f  50                   push eax
// 00932c90  ffd7                 call edi
// 00932c92  8b4e08               mov ecx, dword ptr [esi + 8]
// 00932c95  83c404               add esp, 4
// 00932c98  51                   push ecx
// 00932c99  ffd7                 call edi
// 00932c9b  83c404               add esp, 4
// 00932c9e  5f                   pop edi
// 00932c9f  5e                   pop esi
// 00932ca0  c3                   ret 
// 00932ca1  837e0400             cmp dword ptr [esi + 4], 0
// 00932ca5  742f                 je 0x932cd6
// 00932ca7  8b4e04               mov ecx, dword ptr [esi + 4]
// 00932caa  8b11                 mov edx, dword ptr [ecx]
// 00932cac  8b02                 mov eax, dword ptr [edx]
// 00932cae  6a00                 push 0
// 00932cb0  ffd0                 call eax
// 00932cb2  8b4e04               mov ecx, dword ptr [esi + 4]
// 00932cb5  51                   push ecx
// 00932cb6  ffd7                 call edi
// 00932cb8  8b4e08               mov ecx, dword ptr [esi + 8]
// 00932cbb  83c404               add esp, 4
// 00932cbe  51                   push ecx
// 00932cbf  ffd7                 call edi
// 00932cc1  83c404               add esp, 4
// 00932cc4  5f                   pop edi
// 00932cc5  5e                   pop esi
// 00932cc6  c3                   ret 
// 00932cc7  8b4e04               mov ecx, dword ptr [esi + 4]
// 00932cca  85c9                 test ecx, ecx
// 00932ccc  7408                 je 0x932cd6
// 00932cce  8b11                 mov edx, dword ptr [ecx]
// 00932cd0  8b02                 mov eax, dword ptr [edx]
// 00932cd2  6a01                 push 1
// 00932cd4  ffd0                 call eax
// 00932cd6  8b4e08               mov ecx, dword ptr [esi + 8]
// 00932cd9  51                   push ecx
// 00932cda  ffd7                 call edi
// 00932cdc  83c404               add esp, 4
// 00932cdf  5f                   pop edi
// 00932ce0  5e                   pop esi
// 00932ce1  c3                   ret 
// library ogre-1.7.0/OgreCompositionPass.cpp (function ?destroy@?$SharedPtr@VResource@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositionPass.cpp
