// from server: 100% by auto
// roc 2008-06 00612350  unit: seg_00610000  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612350
//
// 00612350  56                   push esi
// 00612351  8b742408             mov esi, dword ptr [esp + 8]
// 00612355  8b4610               mov eax, dword ptr [esi + 0x10]
// 00612358  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0061235b  57                   push edi
// 0061235c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0061235f  7209                 jb 0x61236a
// 00612361  56                   push esi
// 00612362  e829a00400           call 0x65c390
// 00612367  83c404               add esp, 4
// 0061236a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0061236d  3b4628               cmp eax, dword ptr [esi + 0x28]
// 00612370  7505                 jne 0x612377
// 00612372  8b4648               mov eax, dword ptr [esi + 0x48]
// 00612375  eb08                 jmp 0x61237f
// 00612377  8b5004               mov edx, dword ptr [eax + 4]
// 0061237a  8b02                 mov eax, dword ptr [edx]
// 0061237c  8b400c               mov eax, dword ptr [eax + 0xc]
// 0061237f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00612383  50                   push eax
// 00612384  57                   push edi
// 00612385  56                   push esi
// 00612386  e8c5d00400           call 0x65f450
// 0061238b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0061238f  894810               mov dword ptr [eax + 0x10], ecx
// 00612392  8bcf                 mov ecx, edi
// 00612394  c1e104               shl ecx, 4
// 00612397  294e08               sub dword ptr [esi + 8], ecx
// 0061239a  83c40c               add esp, 0xc
// 0061239d  85ff                 test edi, edi
// 0061239f  7431                 je 0x6123d2
// 006123a1  53                   push ebx
// 006123a2  bbe8ffffff           mov ebx, 0xffffffe8
// 006123a7  55                   push ebp
// 006123a8  8d540118             lea edx, [ecx + eax + 0x18]
// 006123ac  2bd8                 sub ebx, eax
// 006123ae  8bff                 mov edi, edi
// 006123b0  8b4e08               mov ecx, dword ptr [esi + 8]
// 006123b3  83ea10               sub edx, 0x10
// 006123b6  03cb                 add ecx, ebx
// 006123b8  8b2c11               mov ebp, dword ptr [ecx + edx]
// 006123bb  03ca                 add ecx, edx
// 006123bd  892a                 mov dword ptr [edx], ebp
// 006123bf  8b6904               mov ebp, dword ptr [ecx + 4]
// 006123c2  4f                   dec edi
// 006123c3  896a04               mov dword ptr [edx + 4], ebp
// 006123c6  8b4908               mov ecx, dword ptr [ecx + 8]
// 006123c9  894a08               mov dword ptr [edx + 8], ecx
// 006123cc  85ff                 test edi, edi
// 006123ce  75e0                 jne 0x6123b0
// 006123d0  5d                   pop ebp
// 006123d1  5b                   pop ebx
// 006123d2  8b4e08               mov ecx, dword ptr [esi + 8]
// 006123d5  8901                 mov dword ptr [ecx], eax
// 006123d7  c7410806000000       mov dword ptr [ecx + 8], 6
// 006123de  83460810             add dword ptr [esi + 8], 0x10
// 006123e2  5f                   pop edi
// 006123e3  5e                   pop esi
// 006123e4  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushcclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
