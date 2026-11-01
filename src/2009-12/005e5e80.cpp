// from server: 100% by auto
// roc 2009-12 005e5e80  unit: RBX::VBeveledBlockMesh::?$CustomizableMesh  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005e5e80
//
// 005e5e80  8b442404             mov eax, dword ptr [esp + 4]
// 005e5e84  8b4808               mov ecx, dword ptr [eax + 8]
// 005e5e87  80796500             cmp byte ptr [ecx + 0x65], 0
// 005e5e8b  750e                 jne 0x5e5e9b
// 005e5e8d  8d4900               lea ecx, [ecx]
// 005e5e90  8bc1                 mov eax, ecx
// 005e5e92  8b4808               mov ecx, dword ptr [eax + 8]
// 005e5e95  80796500             cmp byte ptr [ecx + 0x65], 0
// 005e5e99  74f5                 je 0x5e5e90
// 005e5e9b  c3                   ret 
// library ogre-1.6.4/OgreCompiler2Pass.cpp (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompiler2Pass.cpp
