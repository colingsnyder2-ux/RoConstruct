// from server: 100% by auto
// roc 2009-06 006b9490  unit: RBX::UniversalTool  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9490
//
// 006b9490  56                   push esi
// 006b9491  8b742408             mov esi, dword ptr [esp + 8]
// 006b9495  8b4610               mov eax, dword ptr [esi + 0x10]
// 006b9498  8b4844               mov ecx, dword ptr [eax + 0x44]
// 006b949b  57                   push edi
// 006b949c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 006b949f  7209                 jb 0x6b94aa
// 006b94a1  56                   push esi
// 006b94a2  e819070300           call 0x6e9bc0
// 006b94a7  83c404               add esp, 4
// 006b94aa  8b4614               mov eax, dword ptr [esi + 0x14]
// 006b94ad  3b4628               cmp eax, dword ptr [esi + 0x28]
// 006b94b0  7505                 jne 0x6b94b7
// 006b94b2  8b4648               mov eax, dword ptr [esi + 0x48]
// 006b94b5  eb08                 jmp 0x6b94bf
// 006b94b7  8b5004               mov edx, dword ptr [eax + 4]
// 006b94ba  8b02                 mov eax, dword ptr [edx]
// 006b94bc  8b400c               mov eax, dword ptr [eax + 0xc]
// 006b94bf  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006b94c3  50                   push eax
// 006b94c4  57                   push edi
// 006b94c5  56                   push esi
// 006b94c6  e8c5370300           call 0x6ecc90
// 006b94cb  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006b94cf  894810               mov dword ptr [eax + 0x10], ecx
// 006b94d2  8bcf                 mov ecx, edi
// 006b94d4  c1e104               shl ecx, 4
// 006b94d7  294e08               sub dword ptr [esi + 8], ecx
// 006b94da  83c40c               add esp, 0xc
// 006b94dd  85ff                 test edi, edi
// 006b94df  7431                 je 0x6b9512
// 006b94e1  53                   push ebx
// 006b94e2  bbe8ffffff           mov ebx, 0xffffffe8
// 006b94e7  55                   push ebp
// 006b94e8  8d540118             lea edx, [ecx + eax + 0x18]
// 006b94ec  2bd8                 sub ebx, eax
// 006b94ee  8bff                 mov edi, edi
// 006b94f0  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b94f3  83ea10               sub edx, 0x10
// 006b94f6  03cb                 add ecx, ebx
// 006b94f8  8b2c11               mov ebp, dword ptr [ecx + edx]
// 006b94fb  03ca                 add ecx, edx
// 006b94fd  892a                 mov dword ptr [edx], ebp
// 006b94ff  8b6904               mov ebp, dword ptr [ecx + 4]
// 006b9502  4f                   dec edi
// 006b9503  896a04               mov dword ptr [edx + 4], ebp
// 006b9506  8b4908               mov ecx, dword ptr [ecx + 8]
// 006b9509  894a08               mov dword ptr [edx + 8], ecx
// 006b950c  85ff                 test edi, edi
// 006b950e  75e0                 jne 0x6b94f0
// 006b9510  5d                   pop ebp
// 006b9511  5b                   pop ebx
// 006b9512  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b9515  8901                 mov dword ptr [ecx], eax
// 006b9517  c7410806000000       mov dword ptr [ecx + 8], 6
// 006b951e  83460810             add dword ptr [esi + 8], 0x10
// 006b9522  5f                   pop edi
// 006b9523  5e                   pop esi
// 006b9524  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushcclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
