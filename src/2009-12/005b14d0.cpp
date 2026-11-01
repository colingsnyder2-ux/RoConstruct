// from server: 100% by auto
// roc 2009-12 005b14d0  unit: RBX::BrickBuilder  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005b14d0
//
// 005b14d0  6a64                 push 0x64
// 005b14d2  e889232400           call 0x7f3860
// 005b14d7  83c404               add esp, 4
// 005b14da  85c0                 test eax, eax
// 005b14dc  7402                 je 0x5b14e0
// 005b14de  8900                 mov dword ptr [eax], eax
// 005b14e0  8d4804               lea ecx, [eax + 4]
// 005b14e3  85c9                 test ecx, ecx
// 005b14e5  7402                 je 0x5b14e9
// 005b14e7  8901                 mov dword ptr [ecx], eax
// 005b14e9  c3                   ret 
// library ogre-1.6.4/OgreResourceGroupManager.cpp (function ?_Buynode@?$list@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@std@@IAEPAU_Node@?$_List_nod@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceGroupManager.cpp
