// from server: 100% by auto
// roc 2009-12 006bda30  unit: CPropGrid::UpdateItemsJob  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006bda30
//
// 006bda30  6a40                 push 0x40
// 006bda32  e8295e1300           call 0x7f3860
// 006bda37  83c404               add esp, 4
// 006bda3a  85c0                 test eax, eax
// 006bda3c  7402                 je 0x6bda40
// 006bda3e  8900                 mov dword ptr [eax], eax
// 006bda40  8d4804               lea ecx, [eax + 4]
// 006bda43  85c9                 test ecx, ecx
// 006bda45  7402                 je 0x6bda49
// 006bda47  8901                 mov dword ptr [ecx], eax
// 006bda49  c3                   ret 
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ?_Buynode@?$list@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
