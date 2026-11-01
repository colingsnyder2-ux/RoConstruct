// from server: 100% by auto
// roc 2010-06 0065b5d0  unit: RBX::ScriptInformationProvider  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065b5d0
//
// 0065b5d0  6a40                 push 0x40
// 0065b5d2  e8c9c31400           call 0x7a79a0
// 0065b5d7  83c404               add esp, 4
// 0065b5da  85c0                 test eax, eax
// 0065b5dc  7402                 je 0x65b5e0
// 0065b5de  8900                 mov dword ptr [eax], eax
// 0065b5e0  8d4804               lea ecx, [eax + 4]
// 0065b5e3  85c9                 test ecx, ecx
// 0065b5e5  7402                 je 0x65b5e9
// 0065b5e7  8901                 mov dword ptr [ecx], eax
// 0065b5e9  c3                   ret 
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ?_Buynode@?$list@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
