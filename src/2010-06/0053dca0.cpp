// from server: 100% by auto
// roc 2010-06 0053dca0  unit: RBX::QuadVolumeBuilder  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053dca0
//
// 0053dca0  8b442404             mov eax, dword ptr [esp + 4]
// 0053dca4  8b4808               mov ecx, dword ptr [eax + 8]
// 0053dca7  80796500             cmp byte ptr [ecx + 0x65], 0
// 0053dcab  750e                 jne 0x53dcbb
// 0053dcad  8d4900               lea ecx, [ecx]
// 0053dcb0  8bc1                 mov eax, ecx
// 0053dcb2  8b4808               mov ecx, dword ptr [eax + 8]
// 0053dcb5  80796500             cmp byte ptr [ecx + 0x65], 0
// 0053dcb9  74f5                 je 0x53dcb0
// 0053dcbb  c3                   ret 
// library ogre-1.6.4/OgreCompiler2Pass.cpp (function ?_Max@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@std@@KAPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@2@PAU342@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompiler2Pass.cpp
