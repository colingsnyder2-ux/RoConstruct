// roc 2012-06 00845b30  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00845b30
//
// 00845b30  8b4104               mov eax, dword ptr [ecx + 4]
// 00845b33  56                   push esi
// 00845b34  8b7004               mov esi, dword ptr [eax + 4]
// 00845b37  807e6500             cmp byte ptr [esi + 0x65], 0
// 00845b3b  57                   push edi
// 00845b3c  8bf8                 mov edi, eax
// 00845b3e  7531                 jne 0x845b71
// 00845b40  53                   push ebx
// 00845b41  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00845b45  55                   push ebp
// 00845b46  8b2d5026b200         mov ebp, dword ptr [0xb22650]
// 00845b4c  8d642400             lea esp, [esp]
// 00845b50  8d460c               lea eax, [esi + 0xc]
// 00845b53  53                   push ebx
// 00845b54  50                   push eax
// 00845b55  ffd5                 call ebp
// 00845b57  83c408               add esp, 8
// 00845b5a  84c0                 test al, al
// 00845b5c  7405                 je 0x845b63
// 00845b5e  8b7608               mov esi, dword ptr [esi + 8]
// 00845b61  eb04                 jmp 0x845b67
// 00845b63  8bfe                 mov edi, esi
// 00845b65  8b36                 mov esi, dword ptr [esi]
// 00845b67  807e6500             cmp byte ptr [esi + 0x65], 0
// 00845b6b  74e3                 je 0x845b50
// 00845b6d  5d                   pop ebp
// 00845b6e  8bc7                 mov eax, edi
// 00845b70  5b                   pop ebx
// 00845b71  5f                   pop edi
// 00845b72  5e                   pop esi
// 00845b73  c20400               ret 4
// copied from an identical function in another client (function ?_Lbound@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@std@@IBEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UTokenState@Compiler2Pass@Ogre@@@std@@@2@$0A@@std@@@2@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
// roc-lib: ogre-1.4.9-dll OgreCompiler2Pass.cpp