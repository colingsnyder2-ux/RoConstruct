// from server: 100% by auto
// roc 2010-06 0068db20  unit: RBX::InsertService  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0068db20
//
// 0068db20  6a30                 push 0x30
// 0068db22  e8799e1100           call 0x7a79a0
// 0068db27  83c404               add esp, 4
// 0068db2a  85c0                 test eax, eax
// 0068db2c  7406                 je 0x68db34
// 0068db2e  c70000000000         mov dword ptr [eax], 0
// 0068db34  8d4804               lea ecx, [eax + 4]
// 0068db37  85c9                 test ecx, ecx
// 0068db39  7406                 je 0x68db41
// 0068db3b  c70100000000         mov dword ptr [ecx], 0
// 0068db41  8d4808               lea ecx, [eax + 8]
// 0068db44  85c9                 test ecx, ecx
// 0068db46  7406                 je 0x68db4e
// 0068db48  c70100000000         mov dword ptr [ecx], 0
// 0068db4e  c6402801             mov byte ptr [eax + 0x28], 1
// 0068db52  c6402900             mov byte ptr [eax + 0x29], 0
// 0068db56  c3                   ret 
// library ogre-1.7.0/OgreResourceManager.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
