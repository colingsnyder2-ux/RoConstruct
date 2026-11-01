// from server: 100% by auto
// roc 2010-06 004c14e0  unit: RBX::Network::Players::W4ChatOption::?$holder  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004c14e0
//
// 004c14e0  6a50                 push 0x50
// 004c14e2  e8b9642e00           call 0x7a79a0
// 004c14e7  83c404               add esp, 4
// 004c14ea  85c0                 test eax, eax
// 004c14ec  7402                 je 0x4c14f0
// 004c14ee  8900                 mov dword ptr [eax], eax
// 004c14f0  8d4804               lea ecx, [eax + 4]
// 004c14f3  85c9                 test ecx, ecx
// 004c14f5  7402                 je 0x4c14f9
// 004c14f7  8901                 mov dword ptr [ecx], eax
// 004c14f9  c3                   ret 
// library ogre-1.6.4/OgreResourceGroupManager.cpp (function ?_Buynode@?$list@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@std@@IAEPAU_Node@?$_List_nod@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceGroupManager.cpp
