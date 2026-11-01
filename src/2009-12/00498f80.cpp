// from server: 100% by auto
// roc 2009-12 00498f80  unit: Ogre::RbxSceneNode  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00498f80
//
// 00498f80  8b442404             mov eax, dword ptr [esp + 4]
// 00498f84  56                   push esi
// 00498f85  8bf1                 mov esi, ecx
// 00498f87  c706e0219b00         mov dword ptr [esi], 0x9b21e0
// 00498f8d  894604               mov dword ptr [esi + 4], eax
// 00498f90  85c0                 test eax, eax
// 00498f92  742b                 je 0x498fbf
// 00498f94  6a00                 push 0
// 00498f96  6a00                 push 0
// 00498f98  6a00                 push 0
// 00498f9a  6a04                 push 4
// 00498f9c  ff15f8bc9800         call dword ptr [0x98bcf8]
// 00498fa2  83c410               add esp, 0x10
// 00498fa5  85c0                 test eax, eax
// 00498fa7  7416                 je 0x498fbf
// 00498fa9  c70001000000         mov dword ptr [eax], 1
// 00498faf  894608               mov dword ptr [esi + 8], eax
// 00498fb2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00498fb6  89460c               mov dword ptr [esi + 0xc], eax
// 00498fb9  8bc6                 mov eax, esi
// 00498fbb  5e                   pop esi
// 00498fbc  c20800               ret 8
// 00498fbf  33c0                 xor eax, eax
// 00498fc1  894608               mov dword ptr [esi + 8], eax
// 00498fc4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00498fc8  89460c               mov dword ptr [esi + 0xc], eax
// 00498fcb  8bc6                 mov eax, esi
// 00498fcd  5e                   pop esi
// 00498fce  c20800               ret 8
// library ogre-1.7.0/OgreConfigFile.cpp (function ??$?0VFileStreamDataStream@Ogre@@@?$SharedPtr@VDataStream@Ogre@@@Ogre@@QAE@PAVFileStreamDataStream@1@W4SharedPtrFreeMethod@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreConfigFile.cpp
