// from server: 100% by auto
// roc 2009-12 006aa700  unit: RBX::ScriptContext  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006aa700
//
// 006aa700  6a18                 push 0x18
// 006aa702  e859911400           call 0x7f3860
// 006aa707  83c404               add esp, 4
// 006aa70a  85c0                 test eax, eax
// 006aa70c  7402                 je 0x6aa710
// 006aa70e  8900                 mov dword ptr [eax], eax
// 006aa710  8d4804               lea ecx, [eax + 4]
// 006aa713  85c9                 test ecx, ecx
// 006aa715  7402                 je 0x6aa719
// 006aa717  8901                 mov dword ptr [ecx], eax
// 006aa719  c3                   ret 
// library ogre-1.6.4/OgreCompositorManager.cpp (function ?_Buynode@?$list@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@std@@IAEPAU_Node@?$_List_nod@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@V?$allocator@V?$SharedPtr@VAbstractNode@Ogre@@@Ogre@@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreCompositorManager.cpp
