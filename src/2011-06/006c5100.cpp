// from server: 100% by auto
// roc 2011-06 006c5100  unit: RBX::ScriptInformationProvider::UCachedScriptInfo::?$AsyncHttpCache  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006c5100
//
// 006c5100  56                   push esi
// 006c5101  6a30                 push 0x30
// 006c5103  e8564f1400           call 0x80a05e
// 006c5108  8bf0                 mov esi, eax
// 006c510a  83c404               add esp, 4
// 006c510d  85f6                 test esi, esi
// 006c510f  7422                 je 0x6c5133
// 006c5111  8b442418             mov eax, dword ptr [esp + 0x18]
// 006c5115  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006c5119  8b542410             mov edx, dword ptr [esp + 0x10]
// 006c511d  50                   push eax
// 006c511e  8b442410             mov eax, dword ptr [esp + 0x10]
// 006c5122  51                   push ecx
// 006c5123  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006c5127  52                   push edx
// 006c5128  50                   push eax
// 006c5129  51                   push ecx
// 006c512a  8bce                 mov ecx, esi
// 006c512c  e8bffeffff           call 0x6c4ff0
// 006c5131  8bc6                 mov eax, esi
// 006c5133  5e                   pop esi
// 006c5134  c21400               ret 0x14
// library ogre-1.7.0/OgreResourceManager.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@2@PAU342@00ABU?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@2@D@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
