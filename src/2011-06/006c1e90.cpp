// from server: 100% by auto
// roc 2011-06 006c1e90  unit: RBX::ScriptInformationProvider  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006c1e90
//
// 006c1e90  6a40                 push 0x40
// 006c1e92  e8c7811400           call 0x80a05e
// 006c1e97  83c404               add esp, 4
// 006c1e9a  85c0                 test eax, eax
// 006c1e9c  7402                 je 0x6c1ea0
// 006c1e9e  8900                 mov dword ptr [eax], eax
// 006c1ea0  8d4804               lea ecx, [eax + 4]
// 006c1ea3  85c9                 test ecx, ecx
// 006c1ea5  7402                 je 0x6c1ea9
// 006c1ea7  8901                 mov dword ptr [ecx], eax
// 006c1ea9  c3                   ret 
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ?_Buynode@?$list@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
