// from server: 100% by auto
// roc 2011-06 00797b00  unit: RBX::VHttp::?$sp_counted_impl_p  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00797b00
//
// 00797b00  55                   push ebp
// 00797b01  8bec                 mov ebp, esp
// 00797b03  6aff                 push -1
// 00797b05  68d1db9f00           push 0x9fdbd1
// 00797b0a  64a100000000         mov eax, dword ptr fs:[0]
// 00797b10  50                   push eax
// 00797b11  64892500000000       mov dword ptr fs:[0], esp
// 00797b18  83ec08               sub esp, 8
// 00797b1b  53                   push ebx
// 00797b1c  56                   push esi
// 00797b1d  57                   push edi
// 00797b1e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00797b21  6a40                 push 0x40
// 00797b23  e836250700           call 0x80a05e
// 00797b28  8bf0                 mov esi, eax
// 00797b2a  83c404               add esp, 4
// 00797b2d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00797b30  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00797b37  85f6                 test esi, esi
// 00797b39  7405                 je 0x797b40
// 00797b3b  8b4508               mov eax, dword ptr [ebp + 8]
// 00797b3e  8906                 mov dword ptr [esi], eax
// 00797b40  8d4604               lea eax, [esi + 4]
// 00797b43  85c0                 test eax, eax
// 00797b45  7405                 je 0x797b4c
// 00797b47  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00797b4a  8908                 mov dword ptr [eax], ecx
// 00797b4c  8d4e08               lea ecx, [esi + 8]
// 00797b4f  894d08               mov dword ptr [ebp + 8], ecx
// 00797b52  894d0c               mov dword ptr [ebp + 0xc], ecx
// 00797b55  c645fc01             mov byte ptr [ebp - 4], 1
// 00797b59  85c9                 test ecx, ecx
// 00797b5b  7409                 je 0x797b66
// 00797b5d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00797b60  52                   push edx
// 00797b61  e85af7ffff           call 0x7972c0
// 00797b66  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00797b69  5f                   pop edi
// 00797b6a  8bc6                 mov eax, esi
// 00797b6c  5e                   pop esi
// 00797b6d  64890d00000000       mov dword ptr fs:[0], ecx
// 00797b74  5b                   pop ebx
// 00797b75  8be5                 mov esp, ebp
// 00797b77  5d                   pop ebp
// 00797b78  c20c00               ret 0xc
// library ogre-1.7.0/OgreScriptTranslator.cpp (function ?_Buynode@?$list@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@V?$allocator@U?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@2@PAU342@0ABU?$pair@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreScriptTranslator.cpp
