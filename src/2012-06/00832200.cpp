// from server: 100% by auto
// roc 2012-06 00832200  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832200
//
// 00832200  56                   push esi
// 00832201  8b742408             mov esi, dword ptr [esp + 8]
// 00832205  8b4610               mov eax, dword ptr [esi + 0x10]
// 00832208  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0083220b  57                   push edi
// 0083220c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0083220f  7209                 jb 0x83221a
// 00832211  56                   push esi
// 00832212  e899101000           call 0x9332b0
// 00832217  83c404               add esp, 4
// 0083221a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0083221d  3b4628               cmp eax, dword ptr [esi + 0x28]
// 00832220  7505                 jne 0x832227
// 00832222  8b4648               mov eax, dword ptr [esi + 0x48]
// 00832225  eb08                 jmp 0x83222f
// 00832227  8b5004               mov edx, dword ptr [eax + 4]
// 0083222a  8b02                 mov eax, dword ptr [edx]
// 0083222c  8b400c               mov eax, dword ptr [eax + 0xc]
// 0083222f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00832233  50                   push eax
// 00832234  57                   push edi
// 00832235  56                   push esi
// 00832236  e855421000           call 0x936490
// 0083223b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0083223f  894810               mov dword ptr [eax + 0x10], ecx
// 00832242  8bcf                 mov ecx, edi
// 00832244  c1e104               shl ecx, 4
// 00832247  294e08               sub dword ptr [esi + 8], ecx
// 0083224a  83c40c               add esp, 0xc
// 0083224d  85ff                 test edi, edi
// 0083224f  7431                 je 0x832282
// 00832251  53                   push ebx
// 00832252  bbe8ffffff           mov ebx, 0xffffffe8
// 00832257  55                   push ebp
// 00832258  8d540118             lea edx, [ecx + eax + 0x18]
// 0083225c  2bd8                 sub ebx, eax
// 0083225e  8bff                 mov edi, edi
// 00832260  8b4e08               mov ecx, dword ptr [esi + 8]
// 00832263  83ea10               sub edx, 0x10
// 00832266  03cb                 add ecx, ebx
// 00832268  8b2c11               mov ebp, dword ptr [ecx + edx]
// 0083226b  03ca                 add ecx, edx
// 0083226d  892a                 mov dword ptr [edx], ebp
// 0083226f  8b6904               mov ebp, dword ptr [ecx + 4]
// 00832272  4f                   dec edi
// 00832273  896a04               mov dword ptr [edx + 4], ebp
// 00832276  8b4908               mov ecx, dword ptr [ecx + 8]
// 00832279  894a08               mov dword ptr [edx + 8], ecx
// 0083227c  85ff                 test edi, edi
// 0083227e  75e0                 jne 0x832260
// 00832280  5d                   pop ebp
// 00832281  5b                   pop ebx
// 00832282  8b4e08               mov ecx, dword ptr [esi + 8]
// 00832285  8901                 mov dword ptr [ecx], eax
// 00832287  c7410806000000       mov dword ptr [ecx + 8], 6
// 0083228e  83460810             add dword ptr [esi + 8], 0x10
// 00832292  5f                   pop edi
// 00832293  5e                   pop esi
// 00832294  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushcclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
