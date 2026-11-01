// from server: 100% by auto
// roc 2011-06 006c1f60  unit: RBX::ScriptInformationProvider  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006c1f60
//
// 006c1f60  55                   push ebp
// 006c1f61  8bec                 mov ebp, esp
// 006c1f63  6aff                 push -1
// 006c1f65  6811259f00           push 0x9f2511
// 006c1f6a  64a100000000         mov eax, dword ptr fs:[0]
// 006c1f70  50                   push eax
// 006c1f71  64892500000000       mov dword ptr fs:[0], esp
// 006c1f78  83ec08               sub esp, 8
// 006c1f7b  53                   push ebx
// 006c1f7c  56                   push esi
// 006c1f7d  57                   push edi
// 006c1f7e  8965f0               mov dword ptr [ebp - 0x10], esp
// 006c1f81  6a40                 push 0x40
// 006c1f83  e8d6801400           call 0x80a05e
// 006c1f88  8bf0                 mov esi, eax
// 006c1f8a  83c404               add esp, 4
// 006c1f8d  8975ec               mov dword ptr [ebp - 0x14], esi
// 006c1f90  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006c1f97  85f6                 test esi, esi
// 006c1f99  7405                 je 0x6c1fa0
// 006c1f9b  8b4508               mov eax, dword ptr [ebp + 8]
// 006c1f9e  8906                 mov dword ptr [esi], eax
// 006c1fa0  8d4604               lea eax, [esi + 4]
// 006c1fa3  85c0                 test eax, eax
// 006c1fa5  7405                 je 0x6c1fac
// 006c1fa7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 006c1faa  8908                 mov dword ptr [eax], ecx
// 006c1fac  8d4e08               lea ecx, [esi + 8]
// 006c1faf  894d08               mov dword ptr [ebp + 8], ecx
// 006c1fb2  894d0c               mov dword ptr [ebp + 0xc], ecx
// 006c1fb5  c645fc01             mov byte ptr [ebp - 4], 1
// 006c1fb9  85c9                 test ecx, ecx
// 006c1fbb  7409                 je 0x6c1fc6
// 006c1fbd  8b5510               mov edx, dword ptr [ebp + 0x10]
// 006c1fc0  52                   push edx
// 006c1fc1  e8cafaffff           call 0x6c1a90
// 006c1fc6  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006c1fc9  5f                   pop edi
// 006c1fca  8bc6                 mov eax, esi
// 006c1fcc  5e                   pop esi
// 006c1fcd  64890d00000000       mov dword ptr fs:[0], ecx
// 006c1fd4  5b                   pop ebx
// 006c1fd5  8be5                 mov esp, ebp
// 006c1fd7  5d                   pop ebp
// 006c1fd8  c20c00               ret 0xc
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ?_Buynode@?$list@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@2@PAU342@0ABU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
