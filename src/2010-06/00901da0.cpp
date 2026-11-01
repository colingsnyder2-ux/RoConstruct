// from server: 100% by auto
// roc 2010-06 00901da0  unit: Ogre::VResource::?$SharedPtr  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00901da0
//
// 00901da0  53                   push ebx
// 00901da1  56                   push esi
// 00901da2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00901da6  8d4604               lea eax, [esi + 4]
// 00901da9  8d5104               lea edx, [ecx + 4]
// 00901dac  57                   push edi
// 00901dad  3bd0                 cmp edx, eax
// 00901daf  7408                 je 0x901db9
// 00901db1  8b18                 mov ebx, dword ptr [eax]
// 00901db3  8b3a                 mov edi, dword ptr [edx]
// 00901db5  891a                 mov dword ptr [edx], ebx
// 00901db7  8938                 mov dword ptr [eax], edi
// 00901db9  8d4608               lea eax, [esi + 8]
// 00901dbc  8d5108               lea edx, [ecx + 8]
// 00901dbf  3bd0                 cmp edx, eax
// 00901dc1  7408                 je 0x901dcb
// 00901dc3  8b18                 mov ebx, dword ptr [eax]
// 00901dc5  8b3a                 mov edi, dword ptr [edx]
// 00901dc7  891a                 mov dword ptr [edx], ebx
// 00901dc9  8938                 mov dword ptr [eax], edi
// 00901dcb  8d460c               lea eax, [esi + 0xc]
// 00901dce  83c10c               add ecx, 0xc
// 00901dd1  3bc8                 cmp ecx, eax
// 00901dd3  7408                 je 0x901ddd
// 00901dd5  8b30                 mov esi, dword ptr [eax]
// 00901dd7  8b11                 mov edx, dword ptr [ecx]
// 00901dd9  8931                 mov dword ptr [ecx], esi
// 00901ddb  8910                 mov dword ptr [eax], edx
// 00901ddd  5f                   pop edi
// 00901dde  5e                   pop esi
// 00901ddf  5b                   pop ebx
// 00901de0  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ?swap@?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@MAEXAAV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
