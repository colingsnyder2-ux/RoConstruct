// from server: 100% by auto
// roc 2009-12 004b3740  unit: Ogre::VRbxFont::?$SharedPtr  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b3740
//
// 004b3740  53                   push ebx
// 004b3741  56                   push esi
// 004b3742  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004b3746  8d4604               lea eax, [esi + 4]
// 004b3749  8d5104               lea edx, [ecx + 4]
// 004b374c  57                   push edi
// 004b374d  3bd0                 cmp edx, eax
// 004b374f  7408                 je 0x4b3759
// 004b3751  8b18                 mov ebx, dword ptr [eax]
// 004b3753  8b3a                 mov edi, dword ptr [edx]
// 004b3755  891a                 mov dword ptr [edx], ebx
// 004b3757  8938                 mov dword ptr [eax], edi
// 004b3759  8d4608               lea eax, [esi + 8]
// 004b375c  8d5108               lea edx, [ecx + 8]
// 004b375f  3bd0                 cmp edx, eax
// 004b3761  7408                 je 0x4b376b
// 004b3763  8b18                 mov ebx, dword ptr [eax]
// 004b3765  8b3a                 mov edi, dword ptr [edx]
// 004b3767  891a                 mov dword ptr [edx], ebx
// 004b3769  8938                 mov dword ptr [eax], edi
// 004b376b  8d460c               lea eax, [esi + 0xc]
// 004b376e  83c10c               add ecx, 0xc
// 004b3771  3bc8                 cmp ecx, eax
// 004b3773  7408                 je 0x4b377d
// 004b3775  8b30                 mov esi, dword ptr [eax]
// 004b3777  8b11                 mov edx, dword ptr [ecx]
// 004b3779  8931                 mov dword ptr [ecx], esi
// 004b377b  8910                 mov dword ptr [eax], edx
// 004b377d  5f                   pop edi
// 004b377e  5e                   pop esi
// 004b377f  5b                   pop ebx
// 004b3780  c20400               ret 4
// library ogre-1.7.0/OgreAnimationTrack.cpp (function ?swap@?$SharedPtr@VAnimableValue@Ogre@@@Ogre@@MAEXAAV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreAnimationTrack.cpp
