// from server: 100% by auto
// roc 2010-06 0065b8a0  unit: RBX::ScriptInformationProvider  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065b8a0
//
// 0065b8a0  55                   push ebp
// 0065b8a1  8bec                 mov ebp, esp
// 0065b8a3  6aff                 push -1
// 0065b8a5  68b1e39900           push 0x99e3b1
// 0065b8aa  64a100000000         mov eax, dword ptr fs:[0]
// 0065b8b0  50                   push eax
// 0065b8b1  64892500000000       mov dword ptr fs:[0], esp
// 0065b8b8  83ec08               sub esp, 8
// 0065b8bb  53                   push ebx
// 0065b8bc  56                   push esi
// 0065b8bd  57                   push edi
// 0065b8be  8965f0               mov dword ptr [ebp - 0x10], esp
// 0065b8c1  6a40                 push 0x40
// 0065b8c3  e8d8c01400           call 0x7a79a0
// 0065b8c8  8bf0                 mov esi, eax
// 0065b8ca  83c404               add esp, 4
// 0065b8cd  8975ec               mov dword ptr [ebp - 0x14], esi
// 0065b8d0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0065b8d7  85f6                 test esi, esi
// 0065b8d9  7405                 je 0x65b8e0
// 0065b8db  8b4508               mov eax, dword ptr [ebp + 8]
// 0065b8de  8906                 mov dword ptr [esi], eax
// 0065b8e0  8d4604               lea eax, [esi + 4]
// 0065b8e3  85c0                 test eax, eax
// 0065b8e5  7405                 je 0x65b8ec
// 0065b8e7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0065b8ea  8908                 mov dword ptr [eax], ecx
// 0065b8ec  8d4e08               lea ecx, [esi + 8]
// 0065b8ef  894d08               mov dword ptr [ebp + 8], ecx
// 0065b8f2  894d0c               mov dword ptr [ebp + 0xc], ecx
// 0065b8f5  c645fc01             mov byte ptr [ebp - 4], 1
// 0065b8f9  85c9                 test ecx, ecx
// 0065b8fb  7409                 je 0x65b906
// 0065b8fd  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0065b900  52                   push edx
// 0065b901  e8fa3ff9ff           call 0x5ef900
// 0065b906  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0065b909  5f                   pop edi
// 0065b90a  8bc6                 mov eax, esi
// 0065b90c  5e                   pop esi
// 0065b90d  64890d00000000       mov dword ptr fs:[0], ecx
// 0065b914  5b                   pop ebx
// 0065b915  8be5                 mov esp, ebp
// 0065b917  5d                   pop ebp
// 0065b918  c20c00               ret 0xc
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ?_Buynode@?$list@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@2@PAU342@0ABU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
