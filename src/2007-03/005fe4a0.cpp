// from server: 100% by auto
// roc 2007-03 005fe4a0  unit: seg_005f0000  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fe4a0
//
// 005fe4a0  83ec1c               sub esp, 0x1c
// 005fe4a3  53                   push ebx
// 005fe4a4  55                   push ebp
// 005fe4a5  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 005fe4a9  56                   push esi
// 005fe4aa  8bf0                 mov esi, eax
// 005fe4ac  8b4610               mov eax, dword ptr [esi + 0x10]
// 005fe4af  83f828               cmp eax, 0x28
// 005fe4b2  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 005fe4b5  57                   push edi
// 005fe4b6  8b7e04               mov edi, dword ptr [esi + 4]
// 005fe4b9  897c2410             mov dword ptr [esp + 0x10], edi
// 005fe4bd  745b                 je 0x5fe51a
// 005fe4bf  83f87b               cmp eax, 0x7b
// 005fe4c2  7449                 je 0x5fe50d
// 005fe4c4  3d1e010000           cmp eax, 0x11e
// 005fe4c9  7416                 je 0x5fe4e1
// 005fe4cb  6894057c00           push 0x7c0594
// 005fe4d0  56                   push esi
// 005fe4d1  e89a2a0000           call 0x600f70
// 005fe4d6  83c408               add esp, 8
// 005fe4d9  5f                   pop edi
// 005fe4da  5e                   pop esi
// 005fe4db  5d                   pop ebp
// 005fe4dc  5b                   pop ebx
// 005fe4dd  83c41c               add esp, 0x1c
// 005fe4e0  c3                   ret 
// 005fe4e1  8b4618               mov eax, dword ptr [esi + 0x18]
// 005fe4e4  50                   push eax
// 005fe4e5  53                   push ebx
// 005fe4e6  e835630100           call 0x614820
// 005fe4eb  83c9ff               or ecx, 0xffffffff
// 005fe4ee  56                   push esi
// 005fe4ef  894c2430             mov dword ptr [esp + 0x30], ecx
// 005fe4f3  894c2434             mov dword ptr [esp + 0x34], ecx
// 005fe4f7  c744242004000000     mov dword ptr [esp + 0x20], 4
// 005fe4ff  89442428             mov dword ptr [esp + 0x28], eax
// 005fe503  e8983e0000           call 0x6023a0
// 005fe508  83c40c               add esp, 0xc
// 005fe50b  eb69                 jmp 0x5fe576
// 005fe50d  8d442414             lea eax, [esp + 0x14]
// 005fe511  8bce                 mov ecx, esi
// 005fe513  e848faffff           call 0x5fdf60
// 005fe518  eb5c                 jmp 0x5fe576
// 005fe51a  3b7e08               cmp edi, dword ptr [esi + 8]
// 005fe51d  740e                 je 0x5fe52d
// 005fe51f  6860057c00           push 0x7c0560
// 005fe524  56                   push esi
// 005fe525  e8462a0000           call 0x600f70
// 005fe52a  83c408               add esp, 8
// 005fe52d  56                   push esi
// 005fe52e  e86d3e0000           call 0x6023a0
// 005fe533  83c404               add esp, 4
// 005fe536  837e1029             cmp dword ptr [esi + 0x10], 0x29
// 005fe53a  750a                 jne 0x5fe546
// 005fe53c  c744241400000000     mov dword ptr [esp + 0x14], 0
// 005fe544  eb1b                 jmp 0x5fe561
// 005fe546  8d7c2414             lea edi, [esp + 0x14]
// 005fe54a  e811ffffff           call 0x5fe460
// 005fe54f  6aff                 push -1
// 005fe551  8bc7                 mov eax, edi
// 005fe553  50                   push eax
// 005fe554  53                   push ebx
// 005fe555  e866630100           call 0x6148c0
// 005fe55a  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 005fe55e  83c40c               add esp, 0xc
// 005fe561  8bc7                 mov eax, edi
// 005fe563  6a28                 push 0x28
// 005fe565  bf29000000           mov edi, 0x29
// 005fe56a  e861efffff           call 0x5fd4d0
// 005fe56f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005fe573  83c404               add esp, 4
// 005fe576  8b442414             mov eax, dword ptr [esp + 0x14]
// 005fe57a  83f80d               cmp eax, 0xd
// 005fe57d  8b7508               mov esi, dword ptr [ebp + 8]
// 005fe580  7421                 je 0x5fe5a3
// 005fe582  83f80e               cmp eax, 0xe
// 005fe585  741c                 je 0x5fe5a3
// 005fe587  85c0                 test eax, eax
// 005fe589  740e                 je 0x5fe599
// 005fe58b  8d4c2414             lea ecx, [esp + 0x14]
// 005fe58f  51                   push ecx
// 005fe590  53                   push ebx
// 005fe591  e82a6c0100           call 0x6151c0
// 005fe596  83c408               add esp, 8
// 005fe599  8b4324               mov eax, dword ptr [ebx + 0x24]
// 005fe59c  2bc6                 sub eax, esi
// 005fe59e  83e801               sub eax, 1
// 005fe5a1  eb03                 jmp 0x5fe5a6
// 005fe5a3  83c8ff               or eax, 0xffffffff
// 005fe5a6  6a02                 push 2
// 005fe5a8  83c001               add eax, 1
// 005fe5ab  50                   push eax
// 005fe5ac  56                   push esi
// 005fe5ad  6a1c                 push 0x1c
// 005fe5af  53                   push ebx
// 005fe5b0  e8fb650100           call 0x614bb0
// 005fe5b5  83c9ff               or ecx, 0xffffffff
// 005fe5b8  57                   push edi
// 005fe5b9  53                   push ebx
// 005fe5ba  894d10               mov dword ptr [ebp + 0x10], ecx
// 005fe5bd  894d14               mov dword ptr [ebp + 0x14], ecx
// 005fe5c0  c745000d000000       mov dword ptr [ebp], 0xd
// 005fe5c7  894508               mov dword ptr [ebp + 8], eax
// 005fe5ca  e821650100           call 0x614af0
// 005fe5cf  83c41c               add esp, 0x1c
// 005fe5d2  83c601               add esi, 1
// 005fe5d5  5f                   pop edi
// 005fe5d6  897324               mov dword ptr [ebx + 0x24], esi
// 005fe5d9  5e                   pop esi
// 005fe5da  5d                   pop ebp
// 005fe5db  5b                   pop ebx
// 005fe5dc  83c41c               add esp, 0x1c
// 005fe5df  c3                   ret 
// library lua-5.1.1/lparser.c (function _funcargs)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
