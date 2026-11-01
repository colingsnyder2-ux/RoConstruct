// from server: 100% by auto
// roc 2010-06 0068dae0  unit: RBX::InsertService  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0068dae0
//
// 0068dae0  56                   push esi
// 0068dae1  6a30                 push 0x30
// 0068dae3  e8b89e1100           call 0x7a79a0
// 0068dae8  8bf0                 mov esi, eax
// 0068daea  83c404               add esp, 4
// 0068daed  85f6                 test esi, esi
// 0068daef  7422                 je 0x68db13
// 0068daf1  8b442418             mov eax, dword ptr [esp + 0x18]
// 0068daf5  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0068daf9  8b542410             mov edx, dword ptr [esp + 0x10]
// 0068dafd  50                   push eax
// 0068dafe  8b442410             mov eax, dword ptr [esp + 0x10]
// 0068db02  51                   push ecx
// 0068db03  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0068db07  52                   push edx
// 0068db08  50                   push eax
// 0068db09  51                   push ecx
// 0068db0a  8bce                 mov ecx, esi
// 0068db0c  e8bffeffff           call 0x68d9d0
// 0068db11  8bc6                 mov eax, esi
// 0068db13  5e                   pop esi
// 0068db14  c21400               ret 0x14
// library ogre-1.7.0/OgreResourceManager.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@00ABU?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@2@D@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
