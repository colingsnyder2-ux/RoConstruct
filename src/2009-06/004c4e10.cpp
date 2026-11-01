// from server: 100% by auto
// roc 2009-06 004c4e10  unit: RBX::Network::Players::Plugin  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c4e10
//
// 004c4e10  6a50                 push 0x50
// 004c4e12  e8213c2500           call 0x718a38
// 004c4e17  83c404               add esp, 4
// 004c4e1a  85c0                 test eax, eax
// 004c4e1c  7402                 je 0x4c4e20
// 004c4e1e  8900                 mov dword ptr [eax], eax
// 004c4e20  8d4804               lea ecx, [eax + 4]
// 004c4e23  85c9                 test ecx, ecx
// 004c4e25  7402                 je 0x4c4e29
// 004c4e27  8901                 mov dword ptr [ecx], eax
// 004c4e29  c3                   ret 
// library ogre-1.6.4/OgreResourceGroupManager.cpp (function ?_Buynode@?$list@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@std@@IAEPAU_Node@?$_List_nod@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceGroupManager.cpp
