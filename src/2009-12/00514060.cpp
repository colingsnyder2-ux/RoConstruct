// from server: 100% by auto
// roc 2009-12 00514060  unit: RBX::Network::Players::W4ChatOption::?$holder  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00514060
//
// 00514060  6a50                 push 0x50
// 00514062  e8f9f72d00           call 0x7f3860
// 00514067  83c404               add esp, 4
// 0051406a  85c0                 test eax, eax
// 0051406c  7402                 je 0x514070
// 0051406e  8900                 mov dword ptr [eax], eax
// 00514070  8d4804               lea ecx, [eax + 4]
// 00514073  85c9                 test ecx, ecx
// 00514075  7402                 je 0x514079
// 00514077  8901                 mov dword ptr [ecx], eax
// 00514079  c3                   ret 
// library ogre-1.6.4/OgreResourceGroupManager.cpp (function ?_Buynode@?$list@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@std@@IAEPAU_Node@?$_List_nod@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceGroupManager.cpp
