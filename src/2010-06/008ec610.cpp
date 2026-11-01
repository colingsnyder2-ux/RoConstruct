// from server: 100% by auto
// roc 2010-06 008ec610  unit: Ogre::RbxSceneNode  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008ec610
//
// 008ec610  8b442404             mov eax, dword ptr [esp + 4]
// 008ec614  56                   push esi
// 008ec615  8bf1                 mov esi, ecx
// 008ec617  c7066081a800         mov dword ptr [esi], 0xa88160
// 008ec61d  894604               mov dword ptr [esi + 4], eax
// 008ec620  85c0                 test eax, eax
// 008ec622  742b                 je 0x8ec64f
// 008ec624  6a00                 push 0
// 008ec626  6a00                 push 0
// 008ec628  6a00                 push 0
// 008ec62a  6a04                 push 4
// 008ec62c  ff1504b89e00         call dword ptr [0x9eb804]
// 008ec632  83c410               add esp, 0x10
// 008ec635  85c0                 test eax, eax
// 008ec637  7416                 je 0x8ec64f
// 008ec639  c70001000000         mov dword ptr [eax], 1
// 008ec63f  894608               mov dword ptr [esi + 8], eax
// 008ec642  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008ec646  89460c               mov dword ptr [esi + 0xc], eax
// 008ec649  8bc6                 mov eax, esi
// 008ec64b  5e                   pop esi
// 008ec64c  c20800               ret 8
// 008ec64f  33c0                 xor eax, eax
// 008ec651  894608               mov dword ptr [esi + 8], eax
// 008ec654  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008ec658  89460c               mov dword ptr [esi + 0xc], eax
// 008ec65b  8bc6                 mov eax, esi
// 008ec65d  5e                   pop esi
// 008ec65e  c20800               ret 8
// library ogre-1.7.0/OgreConfigFile.cpp (function ??$?0VFileStreamDataStream@Ogre@@@?$SharedPtr@VDataStream@Ogre@@@Ogre@@QAE@PAVFileStreamDataStream@1@W4SharedPtrFreeMethod@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreConfigFile.cpp
