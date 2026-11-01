// from server: 100% by auto
// roc 2009-06 00562ca0  unit: RBX::VBeveledBlockMesh::?$CustomizableMesh  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00562ca0
//
// 00562ca0  6a68                 push 0x68
// 00562ca2  e8915d1b00           call 0x718a38
// 00562ca7  83c404               add esp, 4
// 00562caa  85c0                 test eax, eax
// 00562cac  7406                 je 0x562cb4
// 00562cae  c70000000000         mov dword ptr [eax], 0
// 00562cb4  8d4804               lea ecx, [eax + 4]
// 00562cb7  85c9                 test ecx, ecx
// 00562cb9  7406                 je 0x562cc1
// 00562cbb  c70100000000         mov dword ptr [ecx], 0
// 00562cc1  8d4808               lea ecx, [eax + 8]
// 00562cc4  85c9                 test ecx, ecx
// 00562cc6  7406                 je 0x562cce
// 00562cc8  c70100000000         mov dword ptr [ecx], 0
// 00562cce  c6406401             mov byte ptr [eax + 0x64], 1
// 00562cd2  c6406500             mov byte ptr [eax + 0x65], 0
// 00562cd6  c3                   ret 
// library ogre-1.6.4/OgreCompiler2Pass.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompiler2Pass.cpp
