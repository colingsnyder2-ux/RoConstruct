// from server: 100% by auto
// roc 2009-12 004ad220  unit: Ogre::RbxSceneUpdater  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ad220
//
// 004ad220  8b442404             mov eax, dword ptr [esp + 4]
// 004ad224  56                   push esi
// 004ad225  8bf1                 mov esi, ecx
// 004ad227  c70600229b00         mov dword ptr [esi], 0x9b2200
// 004ad22d  894604               mov dword ptr [esi + 4], eax
// 004ad230  85c0                 test eax, eax
// 004ad232  742b                 je 0x4ad25f
// 004ad234  6a00                 push 0
// 004ad236  6a00                 push 0
// 004ad238  6a00                 push 0
// 004ad23a  6a04                 push 4
// 004ad23c  ff15f8bc9800         call dword ptr [0x98bcf8]
// 004ad242  83c410               add esp, 0x10
// 004ad245  85c0                 test eax, eax
// 004ad247  7416                 je 0x4ad25f
// 004ad249  c70001000000         mov dword ptr [eax], 1
// 004ad24f  894608               mov dword ptr [esi + 8], eax
// 004ad252  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004ad256  89460c               mov dword ptr [esi + 0xc], eax
// 004ad259  8bc6                 mov eax, esi
// 004ad25b  5e                   pop esi
// 004ad25c  c20800               ret 8
// 004ad25f  33c0                 xor eax, eax
// 004ad261  894608               mov dword ptr [esi + 8], eax
// 004ad264  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004ad268  89460c               mov dword ptr [esi + 0xc], eax
// 004ad26b  8bc6                 mov eax, esi
// 004ad26d  5e                   pop esi
// 004ad26e  c20800               ret 8
// library ogre-1.7.0/OgreConfigFile.cpp (function ??$?0VFileStreamDataStream@Ogre@@@?$SharedPtr@VDataStream@Ogre@@@Ogre@@QAE@PAVFileStreamDataStream@1@W4SharedPtrFreeMethod@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreConfigFile.cpp
