// from server: 100% by auto
// roc 2007-08 005bdcc0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdcc0
//
// 005bdcc0  56                   push esi
// 005bdcc1  8b742408             mov esi, dword ptr [esp + 8]
// 005bdcc5  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bdcc8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005bdccb  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005bdcce  57                   push edi
// 005bdccf  7209                 jb 0x5bdcda
// 005bdcd1  56                   push esi
// 005bdcd2  e829210500           call 0x60fe00
// 005bdcd7  83c404               add esp, 4
// 005bdcda  8b4614               mov eax, dword ptr [esi + 0x14]
// 005bdcdd  3b4628               cmp eax, dword ptr [esi + 0x28]
// 005bdce0  7505                 jne 0x5bdce7
// 005bdce2  8b4648               mov eax, dword ptr [esi + 0x48]
// 005bdce5  eb08                 jmp 0x5bdcef
// 005bdce7  8b5004               mov edx, dword ptr [eax + 4]
// 005bdcea  8b02                 mov eax, dword ptr [edx]
// 005bdcec  8b400c               mov eax, dword ptr [eax + 0xc]
// 005bdcef  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005bdcf3  50                   push eax
// 005bdcf4  57                   push edi
// 005bdcf5  56                   push esi
// 005bdcf6  e815520500           call 0x612f10
// 005bdcfb  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005bdcff  894810               mov dword ptr [eax + 0x10], ecx
// 005bdd02  8bcf                 mov ecx, edi
// 005bdd04  c1e104               shl ecx, 4
// 005bdd07  294e08               sub dword ptr [esi + 8], ecx
// 005bdd0a  83c40c               add esp, 0xc
// 005bdd0d  85ff                 test edi, edi
// 005bdd0f  7433                 je 0x5bdd44
// 005bdd11  53                   push ebx
// 005bdd12  bbe8ffffff           mov ebx, 0xffffffe8
// 005bdd17  55                   push ebp
// 005bdd18  8d540118             lea edx, [ecx + eax + 0x18]
// 005bdd1c  2bd8                 sub ebx, eax
// 005bdd1e  8bff                 mov edi, edi
// 005bdd20  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bdd23  83ea10               sub edx, 0x10
// 005bdd26  03cb                 add ecx, ebx
// 005bdd28  8b2c11               mov ebp, dword ptr [ecx + edx]
// 005bdd2b  03ca                 add ecx, edx
// 005bdd2d  892a                 mov dword ptr [edx], ebp
// 005bdd2f  8b6904               mov ebp, dword ptr [ecx + 4]
// 005bdd32  83ef01               sub edi, 1
// 005bdd35  85ff                 test edi, edi
// 005bdd37  896a04               mov dword ptr [edx + 4], ebp
// 005bdd3a  8b4908               mov ecx, dword ptr [ecx + 8]
// 005bdd3d  894a08               mov dword ptr [edx + 8], ecx
// 005bdd40  75de                 jne 0x5bdd20
// 005bdd42  5d                   pop ebp
// 005bdd43  5b                   pop ebx
// 005bdd44  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bdd47  8901                 mov dword ptr [ecx], eax
// 005bdd49  c7410806000000       mov dword ptr [ecx + 8], 6
// 005bdd50  83460810             add dword ptr [esi + 8], 0x10
// 005bdd54  5f                   pop edi
// 005bdd55  5e                   pop esi
// 005bdd56  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushcclosure)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
