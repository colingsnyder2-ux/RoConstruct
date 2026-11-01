// from server: 100% by auto
// roc 2009-12 007113e0  unit: RBX::InsertService  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007113e0
//
// 007113e0  6a30                 push 0x30
// 007113e2  e879240e00           call 0x7f3860
// 007113e7  83c404               add esp, 4
// 007113ea  85c0                 test eax, eax
// 007113ec  7406                 je 0x7113f4
// 007113ee  c70000000000         mov dword ptr [eax], 0
// 007113f4  8d4804               lea ecx, [eax + 4]
// 007113f7  85c9                 test ecx, ecx
// 007113f9  7406                 je 0x711401
// 007113fb  c70100000000         mov dword ptr [ecx], 0
// 00711401  8d4808               lea ecx, [eax + 8]
// 00711404  85c9                 test ecx, ecx
// 00711406  7406                 je 0x71140e
// 00711408  c70100000000         mov dword ptr [ecx], 0
// 0071140e  c6402801             mov byte ptr [eax + 0x28], 1
// 00711412  c6402900             mov byte ptr [eax + 0x29], 0
// 00711416  c3                   ret 
// library ogre-1.7.0/OgreResourceManager.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
