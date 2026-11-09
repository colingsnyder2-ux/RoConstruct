// from server: 100% by auto
// roc 2010-06 00721660  unit: RBX::UniversalTool  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721660
//
// 00721660  56                   push esi
// 00721661  8b742408             mov esi, dword ptr [esp + 8]
// 00721665  8b4610               mov eax, dword ptr [esi + 0x10]
// 00721668  8b4844               mov ecx, dword ptr [eax + 0x44]
// 0072166b  57                   push edi
// 0072166c  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 0072166f  7209                 jb 0x72167a
// 00721671  56                   push esi
// 00721672  e8e9970500           call 0x77ae60
// 00721677  83c404               add esp, 4
// 0072167a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0072167d  3b4628               cmp eax, dword ptr [esi + 0x28]
// 00721680  7505                 jne 0x721687
// 00721682  8b4648               mov eax, dword ptr [esi + 0x48]
// 00721685  eb08                 jmp 0x72168f
// 00721687  8b5004               mov edx, dword ptr [eax + 4]
// 0072168a  8b02                 mov eax, dword ptr [edx]
// 0072168c  8b400c               mov eax, dword ptr [eax + 0xc]
// 0072168f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00721693  50                   push eax
// 00721694  57                   push edi
// 00721695  56                   push esi
// 00721696  e895c80500           call 0x77df30
// 0072169b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0072169f  894810               mov dword ptr [eax + 0x10], ecx
// 007216a2  8bcf                 mov ecx, edi
// 007216a4  c1e104               shl ecx, 4
// 007216a7  294e08               sub dword ptr [esi + 8], ecx
// 007216aa  83c40c               add esp, 0xc
// 007216ad  85ff                 test edi, edi
// 007216af  7431                 je 0x7216e2
// 007216b1  53                   push ebx
// 007216b2  bbe8ffffff           mov ebx, 0xffffffe8
// 007216b7  55                   push ebp
// 007216b8  8d540118             lea edx, [ecx + eax + 0x18]
// 007216bc  2bd8                 sub ebx, eax
// 007216be  8bff                 mov edi, edi
// 007216c0  8b4e08               mov ecx, dword ptr [esi + 8]
// 007216c3  83ea10               sub edx, 0x10
// 007216c6  03cb                 add ecx, ebx
// 007216c8  8b2c11               mov ebp, dword ptr [ecx + edx]
// 007216cb  03ca                 add ecx, edx
// 007216cd  892a                 mov dword ptr [edx], ebp
// 007216cf  8b6904               mov ebp, dword ptr [ecx + 4]
// 007216d2  4f                   dec edi
// 007216d3  896a04               mov dword ptr [edx + 4], ebp
// 007216d6  8b4908               mov ecx, dword ptr [ecx + 8]
// 007216d9  894a08               mov dword ptr [edx + 8], ecx
// 007216dc  85ff                 test edi, edi
// 007216de  75e0                 jne 0x7216c0
// 007216e0  5d                   pop ebp
// 007216e1  5b                   pop ebx
// 007216e2  8b4e08               mov ecx, dword ptr [esi + 8]
// 007216e5  8901                 mov dword ptr [ecx], eax
// 007216e7  c7410806000000       mov dword ptr [ecx + 8], 6
// 007216ee  83460810             add dword ptr [esi + 8], 0x10
// 007216f2  5f                   pop edi
// 007216f3  5e                   pop esi
// 007216f4  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushcclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
