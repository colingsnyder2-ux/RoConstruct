// from server: 100% by auto
// roc 2009-12 005e5ea0  unit: RBX::VBeveledBlockMesh::?$CustomizableMesh  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005e5ea0
//
// 005e5ea0  8b442404             mov eax, dword ptr [esp + 4]
// 005e5ea4  8b08                 mov ecx, dword ptr [eax]
// 005e5ea6  80796500             cmp byte ptr [ecx + 0x65], 0
// 005e5eaa  750e                 jne 0x5e5eba
// 005e5eac  8d642400             lea esp, [esp]
// 005e5eb0  8bc1                 mov eax, ecx
// 005e5eb2  8b08                 mov ecx, dword ptr [eax]
// 005e5eb4  80796500             cmp byte ptr [ecx + 0x65], 0
// 005e5eb8  74f6                 je 0x5e5eb0
// 005e5eba  c3                   ret 
// library ogre-1.6.4/OgreCompiler2Pass.cpp (function ?_Min@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompiler2Pass.cpp
