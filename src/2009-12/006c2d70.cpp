// from server: 100% by auto
// roc 2009-12 006c2d70  unit: RBX::VContentProvider::?$BoundFuncDesc  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006c2d70
//
// 006c2d70  55                   push ebp
// 006c2d71  8bec                 mov ebp, esp
// 006c2d73  6aff                 push -1
// 006c2d75  6861929400           push 0x949261
// 006c2d7a  64a100000000         mov eax, dword ptr fs:[0]
// 006c2d80  50                   push eax
// 006c2d81  64892500000000       mov dword ptr fs:[0], esp
// 006c2d88  83ec08               sub esp, 8
// 006c2d8b  53                   push ebx
// 006c2d8c  56                   push esi
// 006c2d8d  57                   push edi
// 006c2d8e  8965f0               mov dword ptr [ebp - 0x10], esp
// 006c2d91  6a40                 push 0x40
// 006c2d93  e8c80a1300           call 0x7f3860
// 006c2d98  8bf0                 mov esi, eax
// 006c2d9a  83c404               add esp, 4
// 006c2d9d  8975ec               mov dword ptr [ebp - 0x14], esi
// 006c2da0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006c2da7  85f6                 test esi, esi
// 006c2da9  7405                 je 0x6c2db0
// 006c2dab  8b4508               mov eax, dword ptr [ebp + 8]
// 006c2dae  8906                 mov dword ptr [esi], eax
// 006c2db0  8d4604               lea eax, [esi + 4]
// 006c2db3  85c0                 test eax, eax
// 006c2db5  7405                 je 0x6c2dbc
// 006c2db7  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 006c2dba  8908                 mov dword ptr [eax], ecx
// 006c2dbc  8d4e08               lea ecx, [esi + 8]
// 006c2dbf  894d08               mov dword ptr [ebp + 8], ecx
// 006c2dc2  894d0c               mov dword ptr [ebp + 0xc], ecx
// 006c2dc5  c645fc01             mov byte ptr [ebp - 4], 1
// 006c2dc9  85c9                 test ecx, ecx
// 006c2dcb  7409                 je 0x6c2dd6
// 006c2dcd  8b5510               mov edx, dword ptr [ebp + 0x10]
// 006c2dd0  52                   push edx
// 006c2dd1  e88af2ffff           call 0x6c2060
// 006c2dd6  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006c2dd9  5f                   pop edi
// 006c2dda  8bc6                 mov eax, esi
// 006c2ddc  5e                   pop esi
// 006c2ddd  64890d00000000       mov dword ptr fs:[0], ecx
// 006c2de4  5b                   pop ebx
// 006c2de5  8be5                 mov esp, ebp
// 006c2de7  5d                   pop ebp
// 006c2de8  c20c00               ret 0xc
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ?_Buynode@?$list@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@2@PAU342@0ABU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
