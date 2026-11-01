// from server: 100% by auto
// roc 2010-06 0053e050  unit: RBX::QuadVolumeBuilder  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053e050
//
// 0053e050  6a68                 push 0x68
// 0053e052  e849992600           call 0x7a79a0
// 0053e057  83c404               add esp, 4
// 0053e05a  85c0                 test eax, eax
// 0053e05c  7406                 je 0x53e064
// 0053e05e  c70000000000         mov dword ptr [eax], 0
// 0053e064  8d4804               lea ecx, [eax + 4]
// 0053e067  85c9                 test ecx, ecx
// 0053e069  7406                 je 0x53e071
// 0053e06b  c70100000000         mov dword ptr [ecx], 0
// 0053e071  8d4808               lea ecx, [eax + 8]
// 0053e074  85c9                 test ecx, ecx
// 0053e076  7406                 je 0x53e07e
// 0053e078  c70100000000         mov dword ptr [ecx], 0
// 0053e07e  c6406401             mov byte ptr [eax + 0x64], 1
// 0053e082  c6406500             mov byte ptr [eax + 0x65], 0
// 0053e086  c3                   ret 
// library ogre-1.6.4/OgreCompiler2Pass.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompiler2Pass.cpp
