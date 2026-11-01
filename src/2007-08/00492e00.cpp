// from server: 100% by auto
// roc 2007-08 00492e00  unit: RBX::Network::Players  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00492e00
//
// 00492e00  55                   push ebp
// 00492e01  8bec                 mov ebp, esp
// 00492e03  6aff                 push -1
// 00492e05  68207e7400           push 0x747e20
// 00492e0a  64a100000000         mov eax, dword ptr fs:[0]
// 00492e10  50                   push eax
// 00492e11  83ec08               sub esp, 8
// 00492e14  53                   push ebx
// 00492e15  56                   push esi
// 00492e16  57                   push edi
// 00492e17  a188518b00           mov eax, dword ptr [0x8b5188]
// 00492e1c  33c5                 xor eax, ebp
// 00492e1e  50                   push eax
// 00492e1f  8d45f4               lea eax, [ebp - 0xc]
// 00492e22  64a300000000         mov dword ptr fs:[0], eax
// 00492e28  8965f0               mov dword ptr [ebp - 0x10], esp
// 00492e2b  6a28                 push 0x28
// 00492e2d  e8c4d01900           call 0x62fef6
// 00492e32  8bf0                 mov esi, eax
// 00492e34  83c404               add esp, 4
// 00492e37  85f6                 test esi, esi
// 00492e39  8975ec               mov dword ptr [ebp - 0x14], esi
// 00492e3c  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00492e43  7405                 je 0x492e4a
// 00492e45  8b4508               mov eax, dword ptr [ebp + 8]
// 00492e48  8906                 mov dword ptr [esi], eax
// 00492e4a  8d4604               lea eax, [esi + 4]
// 00492e4d  85c0                 test eax, eax
// 00492e4f  7405                 je 0x492e56
// 00492e51  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00492e54  8908                 mov dword ptr [eax], ecx
// 00492e56  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00492e59  52                   push edx
// 00492e5a  8d4608               lea eax, [esi + 8]
// 00492e5d  50                   push eax
// 00492e5e  e8adecffff           call 0x491b10
// 00492e63  83c408               add esp, 8
// 00492e66  8bc6                 mov eax, esi
// 00492e68  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00492e6b  64890d00000000       mov dword ptr fs:[0], ecx
// 00492e72  59                   pop ecx
// 00492e73  5f                   pop edi
// 00492e74  5e                   pop esi
// 00492e75  5b                   pop ebx
// 00492e76  8be5                 mov esp, ebp
// 00492e78  5d                   pop ebp
// 00492e79  c20c00               ret 0xc
// library ogre-1.7.0/OgreMesh.cpp (function ?_Buynode@?$list@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@@2@PAU342@0ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
