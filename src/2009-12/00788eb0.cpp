// from server: 100% by auto
// roc 2009-12 00788eb0  unit: RBX::UniversalTool  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788eb0
//
// 00788eb0  56                   push esi
// 00788eb1  8b742408             mov esi, dword ptr [esp + 8]
// 00788eb5  8b4610               mov eax, dword ptr [esi + 0x10]
// 00788eb8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00788ebb  57                   push edi
// 00788ebc  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00788ebf  7209                 jb 0x788eca
// 00788ec1  56                   push esi
// 00788ec2  e8494d0400           call 0x7cdc10
// 00788ec7  83c404               add esp, 4
// 00788eca  8b4614               mov eax, dword ptr [esi + 0x14]
// 00788ecd  3b4628               cmp eax, dword ptr [esi + 0x28]
// 00788ed0  7505                 jne 0x788ed7
// 00788ed2  8b4648               mov eax, dword ptr [esi + 0x48]
// 00788ed5  eb08                 jmp 0x788edf
// 00788ed7  8b5004               mov edx, dword ptr [eax + 4]
// 00788eda  8b02                 mov eax, dword ptr [edx]
// 00788edc  8b400c               mov eax, dword ptr [eax + 0xc]
// 00788edf  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00788ee3  50                   push eax
// 00788ee4  57                   push edi
// 00788ee5  56                   push esi
// 00788ee6  e8f57d0400           call 0x7d0ce0
// 00788eeb  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00788eef  894810               mov dword ptr [eax + 0x10], ecx
// 00788ef2  8bcf                 mov ecx, edi
// 00788ef4  c1e104               shl ecx, 4
// 00788ef7  294e08               sub dword ptr [esi + 8], ecx
// 00788efa  83c40c               add esp, 0xc
// 00788efd  85ff                 test edi, edi
// 00788eff  7431                 je 0x788f32
// 00788f01  53                   push ebx
// 00788f02  bbe8ffffff           mov ebx, 0xffffffe8
// 00788f07  55                   push ebp
// 00788f08  8d540118             lea edx, [ecx + eax + 0x18]
// 00788f0c  2bd8                 sub ebx, eax
// 00788f0e  8bff                 mov edi, edi
// 00788f10  8b4e08               mov ecx, dword ptr [esi + 8]
// 00788f13  83ea10               sub edx, 0x10
// 00788f16  03cb                 add ecx, ebx
// 00788f18  8b2c11               mov ebp, dword ptr [ecx + edx]
// 00788f1b  03ca                 add ecx, edx
// 00788f1d  892a                 mov dword ptr [edx], ebp
// 00788f1f  8b6904               mov ebp, dword ptr [ecx + 4]
// 00788f22  4f                   dec edi
// 00788f23  896a04               mov dword ptr [edx + 4], ebp
// 00788f26  8b4908               mov ecx, dword ptr [ecx + 8]
// 00788f29  894a08               mov dword ptr [edx + 8], ecx
// 00788f2c  85ff                 test edi, edi
// 00788f2e  75e0                 jne 0x788f10
// 00788f30  5d                   pop ebp
// 00788f31  5b                   pop ebx
// 00788f32  8b4e08               mov ecx, dword ptr [esi + 8]
// 00788f35  8901                 mov dword ptr [ecx], eax
// 00788f37  c7410806000000       mov dword ptr [ecx + 8], 6
// 00788f3e  83460810             add dword ptr [esi + 8], 0x10
// 00788f42  5f                   pop edi
// 00788f43  5e                   pop esi
// 00788f44  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushcclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
