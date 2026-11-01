// from server: 100% by auto
// roc 2011-06 00775b50  unit: RBX::LibraryService::VLibraryStateObject::?$sp_counted_impl_p  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00775b50
//
// 00775b50  55                   push ebp
// 00775b51  8bec                 mov ebp, esp
// 00775b53  6aff                 push -1
// 00775b55  68e0b19f00           push 0x9fb1e0
// 00775b5a  64a100000000         mov eax, dword ptr fs:[0]
// 00775b60  50                   push eax
// 00775b61  64892500000000       mov dword ptr fs:[0], esp
// 00775b68  83ec08               sub esp, 8
// 00775b6b  53                   push ebx
// 00775b6c  56                   push esi
// 00775b6d  57                   push edi
// 00775b6e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00775b71  6a28                 push 0x28
// 00775b73  e8e6440900           call 0x80a05e
// 00775b78  8bf0                 mov esi, eax
// 00775b7a  83c404               add esp, 4
// 00775b7d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00775b80  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00775b87  85f6                 test esi, esi
// 00775b89  7405                 je 0x775b90
// 00775b8b  8b4508               mov eax, dword ptr [ebp + 8]
// 00775b8e  8906                 mov dword ptr [esi], eax
// 00775b90  8d4604               lea eax, [esi + 4]
// 00775b93  85c0                 test eax, eax
// 00775b95  7405                 je 0x775b9c
// 00775b97  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00775b9a  8908                 mov dword ptr [eax], ecx
// 00775b9c  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00775b9f  52                   push edx
// 00775ba0  8d4608               lea eax, [esi + 8]
// 00775ba3  50                   push eax
// 00775ba4  e837ecffff           call 0x7747e0
// 00775ba9  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00775bac  83c408               add esp, 8
// 00775baf  5f                   pop edi
// 00775bb0  8bc6                 mov eax, esi
// 00775bb2  5e                   pop esi
// 00775bb3  64890d00000000       mov dword ptr fs:[0], ecx
// 00775bba  5b                   pop ebx
// 00775bbb  8be5                 mov esp, ebp
// 00775bbd  5d                   pop ebp
// 00775bbe  c20c00               ret 0xc
// library ogre-1.7.0/OgreMesh.cpp (function ?_Buynode@?$list@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@@std@@IAEPAU_Node@?$_List_nod@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@std@@@2@@2@PAU342@0ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@G@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreMesh.cpp
