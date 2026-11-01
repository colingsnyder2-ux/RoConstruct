// from server: 100% by auto
// roc 2011-06 009224f0  unit: RBX::AdornRbxGfx  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009224f0
//
// 009224f0  8b442404             mov eax, dword ptr [esp + 4]
// 009224f4  56                   push esi
// 009224f5  8bf1                 mov esi, ecx
// 009224f7  c706984baf00         mov dword ptr [esi], 0xaf4b98
// 009224fd  894604               mov dword ptr [esi + 4], eax
// 00922500  85c0                 test eax, eax
// 00922502  742b                 je 0x92252f
// 00922504  6a00                 push 0
// 00922506  6a00                 push 0
// 00922508  6a00                 push 0
// 0092250a  6a04                 push 4
// 0092250c  ff15a417a400         call dword ptr [0xa417a4]
// 00922512  83c410               add esp, 0x10
// 00922515  85c0                 test eax, eax
// 00922517  7416                 je 0x92252f
// 00922519  c70001000000         mov dword ptr [eax], 1
// 0092251f  894608               mov dword ptr [esi + 8], eax
// 00922522  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00922526  89460c               mov dword ptr [esi + 0xc], eax
// 00922529  8bc6                 mov eax, esi
// 0092252b  5e                   pop esi
// 0092252c  c20800               ret 8
// 0092252f  33c0                 xor eax, eax
// 00922531  894608               mov dword ptr [esi + 8], eax
// 00922534  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00922538  89460c               mov dword ptr [esi + 0xc], eax
// 0092253b  8bc6                 mov eax, esi
// 0092253d  5e                   pop esi
// 0092253e  c20800               ret 8
// library ogre-1.7.0/OgreConfigFile.cpp (function ??$?0VFileStreamDataStream@Ogre@@@?$SharedPtr@VDataStream@Ogre@@@Ogre@@QAE@PAVFileStreamDataStream@1@W4SharedPtrFreeMethod@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreConfigFile.cpp
