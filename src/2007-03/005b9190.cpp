// from server: 100% by auto
// roc 2007-03 005b9190  unit: seg_005b0000  size: 151 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9190
//
// 005b9190  56                   push esi
// 005b9191  8b742408             mov esi, dword ptr [esp + 8]
// 005b9195  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b9198  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005b919b  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005b919e  57                   push edi
// 005b919f  7209                 jb 0x5b91aa
// 005b91a1  56                   push esi
// 005b91a2  e809060400           call 0x5f97b0
// 005b91a7  83c404               add esp, 4
// 005b91aa  8b4614               mov eax, dword ptr [esi + 0x14]
// 005b91ad  3b4628               cmp eax, dword ptr [esi + 0x28]
// 005b91b0  7505                 jne 0x5b91b7
// 005b91b2  8b4648               mov eax, dword ptr [esi + 0x48]
// 005b91b5  eb08                 jmp 0x5b91bf
// 005b91b7  8b5004               mov edx, dword ptr [eax + 4]
// 005b91ba  8b02                 mov eax, dword ptr [edx]
// 005b91bc  8b400c               mov eax, dword ptr [eax + 0xc]
// 005b91bf  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005b91c3  50                   push eax
// 005b91c4  57                   push edi
// 005b91c5  56                   push esi
// 005b91c6  e8f5360400           call 0x5fc8c0
// 005b91cb  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005b91cf  894810               mov dword ptr [eax + 0x10], ecx
// 005b91d2  8bcf                 mov ecx, edi
// 005b91d4  c1e104               shl ecx, 4
// 005b91d7  294e08               sub dword ptr [esi + 8], ecx
// 005b91da  83c40c               add esp, 0xc
// 005b91dd  85ff                 test edi, edi
// 005b91df  7433                 je 0x5b9214
// 005b91e1  53                   push ebx
// 005b91e2  bbe8ffffff           mov ebx, 0xffffffe8
// 005b91e7  55                   push ebp
// 005b91e8  8d540118             lea edx, [ecx + eax + 0x18]
// 005b91ec  2bd8                 sub ebx, eax
// 005b91ee  8bff                 mov edi, edi
// 005b91f0  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b91f3  83ea10               sub edx, 0x10
// 005b91f6  03cb                 add ecx, ebx
// 005b91f8  8b2c11               mov ebp, dword ptr [ecx + edx]
// 005b91fb  03ca                 add ecx, edx
// 005b91fd  892a                 mov dword ptr [edx], ebp
// 005b91ff  8b6904               mov ebp, dword ptr [ecx + 4]
// 005b9202  83ef01               sub edi, 1
// 005b9205  85ff                 test edi, edi
// 005b9207  896a04               mov dword ptr [edx + 4], ebp
// 005b920a  8b4908               mov ecx, dword ptr [ecx + 8]
// 005b920d  894a08               mov dword ptr [edx + 8], ecx
// 005b9210  75de                 jne 0x5b91f0
// 005b9212  5d                   pop ebp
// 005b9213  5b                   pop ebx
// 005b9214  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b9217  8901                 mov dword ptr [ecx], eax
// 005b9219  c7410806000000       mov dword ptr [ecx + 8], 6
// 005b9220  83460810             add dword ptr [esi + 8], 0x10
// 005b9224  5f                   pop edi
// 005b9225  5e                   pop esi
// 005b9226  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_pushcclosure)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
