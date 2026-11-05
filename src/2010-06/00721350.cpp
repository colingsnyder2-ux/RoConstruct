// from server: 100% by auto
// roc 2010-06 00721350  unit: RBX::UniversalTool  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00721350
//
// 00721350  56                   push esi
// 00721351  8b742408             mov esi, dword ptr [esp + 8]
// 00721355  57                   push edi
// 00721356  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0072135a  8bc7                 mov eax, edi
// 0072135c  8bce                 mov ecx, esi
// 0072135e  e83dfaffff           call 0x720da0
// 00721363  83780804             cmp dword ptr [eax + 8], 4
// 00721367  743e                 je 0x7213a7
// 00721369  50                   push eax
// 0072136a  56                   push esi
// 0072136b  e8109e0500           call 0x77b180
// 00721370  83c408               add esp, 8
// 00721373  85c0                 test eax, eax
// 00721375  7513                 jne 0x72138a
// 00721377  8b442414             mov eax, dword ptr [esp + 0x14]
// 0072137b  85c0                 test eax, eax
// 0072137d  7406                 je 0x721385
// 0072137f  c70000000000         mov dword ptr [eax], 0
// 00721385  5f                   pop edi
// 00721386  33c0                 xor eax, eax
// 00721388  5e                   pop esi
// 00721389  c3                   ret 
// 0072138a  8b4610               mov eax, dword ptr [esi + 0x10]
// 0072138d  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00721390  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00721393  7209                 jb 0x72139e
// 00721395  56                   push esi
// 00721396  e8c59a0500           call 0x77ae60
// 0072139b  83c404               add esp, 4
// 0072139e  8bc7                 mov eax, edi
// 007213a0  8bce                 mov ecx, esi
// 007213a2  e8f9f9ffff           call 0x720da0
// 007213a7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007213ab  85c9                 test ecx, ecx
// 007213ad  7407                 je 0x7213b6
// 007213af  8b10                 mov edx, dword ptr [eax]
// 007213b1  8b520c               mov edx, dword ptr [edx + 0xc]
// 007213b4  8911                 mov dword ptr [ecx], edx
// 007213b6  8b00                 mov eax, dword ptr [eax]
// 007213b8  5f                   pop edi
// 007213b9  83c010               add eax, 0x10
// 007213bc  5e                   pop esi
// 007213bd  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tolstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
