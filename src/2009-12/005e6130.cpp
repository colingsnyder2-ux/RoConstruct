// from server: 100% by auto
// roc 2009-12 005e6130  unit: RBX::VBeveledBlockMesh::?$CustomizableMesh  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005e6130
//
// 005e6130  6a68                 push 0x68
// 005e6132  e829d72000           call 0x7f3860
// 005e6137  83c404               add esp, 4
// 005e613a  85c0                 test eax, eax
// 005e613c  7406                 je 0x5e6144
// 005e613e  c70000000000         mov dword ptr [eax], 0
// 005e6144  8d4804               lea ecx, [eax + 4]
// 005e6147  85c9                 test ecx, ecx
// 005e6149  7406                 je 0x5e6151
// 005e614b  c70100000000         mov dword ptr [ecx], 0
// 005e6151  8d4808               lea ecx, [eax + 8]
// 005e6154  85c9                 test ecx, ecx
// 005e6156  7406                 je 0x5e615e
// 005e6158  c70100000000         mov dword ptr [ecx], 0
// 005e615e  c6406401             mov byte ptr [eax + 0x64], 1
// 005e6162  c6406500             mov byte ptr [eax + 0x65], 0
// 005e6166  c3                   ret 
// library ogre-1.6.4/OgreCompiler2Pass.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompiler2Pass.cpp
