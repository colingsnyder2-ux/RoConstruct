// from server: 100% by auto
// roc 2010-06 0096f580  unit: seg_00960000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096f580
//
// 0096f580  6a64                 push 0x64
// 0096f582  e81984e3ff           call 0x7a79a0
// 0096f587  83c404               add esp, 4
// 0096f58a  85c0                 test eax, eax
// 0096f58c  7402                 je 0x96f590
// 0096f58e  8900                 mov dword ptr [eax], eax
// 0096f590  8d4804               lea ecx, [eax + 4]
// 0096f593  85c9                 test ecx, ecx
// 0096f595  7402                 je 0x96f599
// 0096f597  8901                 mov dword ptr [ecx], eax
// 0096f599  c3                   ret 
// library ogre-1.6.4/OgreResourceGroupManager.cpp (function ?_Buynode@?$list@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@std@@IAEPAU_Node@?$_List_nod@UResourceDeclaration@ResourceGroupManager@Ogre@@V?$allocator@UResourceDeclaration@ResourceGroupManager@Ogre@@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreResourceGroupManager.cpp
