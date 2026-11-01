// from server: 100% by auto
// roc 2009-12 007113a0  unit: RBX::InsertService  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007113a0
//
// 007113a0  56                   push esi
// 007113a1  6a30                 push 0x30
// 007113a3  e8b8240e00           call 0x7f3860
// 007113a8  8bf0                 mov esi, eax
// 007113aa  83c404               add esp, 4
// 007113ad  85f6                 test esi, esi
// 007113af  7422                 je 0x7113d3
// 007113b1  8b442418             mov eax, dword ptr [esp + 0x18]
// 007113b5  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007113b9  8b542410             mov edx, dword ptr [esp + 0x10]
// 007113bd  50                   push eax
// 007113be  8b442410             mov eax, dword ptr [esp + 0x10]
// 007113c2  51                   push ecx
// 007113c3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007113c7  52                   push edx
// 007113c8  50                   push eax
// 007113c9  51                   push ecx
// 007113ca  8bce                 mov ecx, esi
// 007113cc  e8bffeffff           call 0x711290
// 007113d1  8bc6                 mov eax, esi
// 007113d3  5e                   pop esi
// 007113d4  c21400               ret 0x14
// library ogre-1.7.0/OgreResourceManager.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@00ABU?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@2@D@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
