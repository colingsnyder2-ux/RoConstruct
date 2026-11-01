// from server: 100% by auto
// roc 2011-06 006c5140  unit: RBX::ScriptInformationProvider::UCachedScriptInfo::?$AsyncHttpCache  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006c5140
//
// 006c5140  6a30                 push 0x30
// 006c5142  e8174f1400           call 0x80a05e
// 006c5147  83c404               add esp, 4
// 006c514a  85c0                 test eax, eax
// 006c514c  7406                 je 0x6c5154
// 006c514e  c70000000000         mov dword ptr [eax], 0
// 006c5154  8d4804               lea ecx, [eax + 4]
// 006c5157  85c9                 test ecx, ecx
// 006c5159  7406                 je 0x6c5161
// 006c515b  c70100000000         mov dword ptr [ecx], 0
// 006c5161  8d4808               lea ecx, [eax + 8]
// 006c5164  85c9                 test ecx, ecx
// 006c5166  7406                 je 0x6c516e
// 006c5168  c70100000000         mov dword ptr [ecx], 0
// 006c516e  c6402801             mov byte ptr [eax + 0x28], 1
// 006c5172  c6402900             mov byte ptr [eax + 0x29], 0
// 006c5176  c3                   ret 
// library ogre-1.7.0/OgreResourceManager.cpp (function ?_Buynode@?$_Tree@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@_KV?$SharedPtr@VResource@Ogre@@@Ogre@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KV?$SharedPtr@VResource@Ogre@@@Ogre@@@std@@@4@$0A@@std@@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreResourceManager.cpp
