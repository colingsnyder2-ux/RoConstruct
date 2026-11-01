// from server: 100% by auto
// roc 2011-06 0093d8b0  unit: Ogre::VResource::?$SharedPtr  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0093d8b0
//
// 0093d8b0  53                   push ebx
// 0093d8b1  56                   push esi
// 0093d8b2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0093d8b6  8d4604               lea eax, [esi + 4]
// 0093d8b9  8d5104               lea edx, [ecx + 4]
// 0093d8bc  57                   push edi
// 0093d8bd  3bd0                 cmp edx, eax
// 0093d8bf  7408                 je 0x93d8c9
// 0093d8c1  8b18                 mov ebx, dword ptr [eax]
// 0093d8c3  8b3a                 mov edi, dword ptr [edx]
// 0093d8c5  891a                 mov dword ptr [edx], ebx
// 0093d8c7  8938                 mov dword ptr [eax], edi
// 0093d8c9  8d4608               lea eax, [esi + 8]
// 0093d8cc  8d5108               lea edx, [ecx + 8]
// 0093d8cf  3bd0                 cmp edx, eax
// 0093d8d1  7408                 je 0x93d8db
// 0093d8d3  8b18                 mov ebx, dword ptr [eax]
// 0093d8d5  8b3a                 mov edi, dword ptr [edx]
// 0093d8d7  891a                 mov dword ptr [edx], ebx
// 0093d8d9  8938                 mov dword ptr [eax], edi
// 0093d8db  8d460c               lea eax, [esi + 0xc]
// 0093d8de  83c10c               add ecx, 0xc
// 0093d8e1  3bc8                 cmp ecx, eax
// 0093d8e3  7408                 je 0x93d8ed
// 0093d8e5  8b30                 mov esi, dword ptr [eax]
// 0093d8e7  8b11                 mov edx, dword ptr [ecx]
// 0093d8e9  8931                 mov dword ptr [ecx], esi
// 0093d8eb  8910                 mov dword ptr [eax], edx
// 0093d8ed  5f                   pop edi
// 0093d8ee  5e                   pop esi
// 0093d8ef  5b                   pop ebx
// 0093d8f0  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ?swap@?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@MAEXAAV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
