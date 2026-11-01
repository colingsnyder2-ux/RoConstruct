// from server: 100% by auto
// roc 2010-06 00900880  unit: Ogre::RbxSceneUpdater  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00900880
//
// 00900880  8b442404             mov eax, dword ptr [esp + 4]
// 00900884  56                   push esi
// 00900885  8bf1                 mov esi, ecx
// 00900887  c7067081a800         mov dword ptr [esi], 0xa88170
// 0090088d  894604               mov dword ptr [esi + 4], eax
// 00900890  85c0                 test eax, eax
// 00900892  742b                 je 0x9008bf
// 00900894  6a00                 push 0
// 00900896  6a00                 push 0
// 00900898  6a00                 push 0
// 0090089a  6a04                 push 4
// 0090089c  ff1504b89e00         call dword ptr [0x9eb804]
// 009008a2  83c410               add esp, 0x10
// 009008a5  85c0                 test eax, eax
// 009008a7  7416                 je 0x9008bf
// 009008a9  c70001000000         mov dword ptr [eax], 1
// 009008af  894608               mov dword ptr [esi + 8], eax
// 009008b2  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009008b6  89460c               mov dword ptr [esi + 0xc], eax
// 009008b9  8bc6                 mov eax, esi
// 009008bb  5e                   pop esi
// 009008bc  c20800               ret 8
// 009008bf  33c0                 xor eax, eax
// 009008c1  894608               mov dword ptr [esi + 8], eax
// 009008c4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009008c8  89460c               mov dword ptr [esi + 0xc], eax
// 009008cb  8bc6                 mov eax, esi
// 009008cd  5e                   pop esi
// 009008ce  c20800               ret 8
// library ogre-1.7.0/OgreConfigFile.cpp (function ??$?0VFileStreamDataStream@Ogre@@@?$SharedPtr@VDataStream@Ogre@@@Ogre@@QAE@PAVFileStreamDataStream@1@W4SharedPtrFreeMethod@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreConfigFile.cpp
