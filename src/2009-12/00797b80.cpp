// from server: 100% by auto
// roc 2009-12 00797b80  unit: lua_exception  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00797b80
//
// 00797b80  56                   push esi
// 00797b81  8b742408             mov esi, dword ptr [esp + 8]
// 00797b85  807e0600             cmp byte ptr [esi + 6], 0
// 00797b89  8b4614               mov eax, dword ptr [esi + 0x14]
// 00797b8c  7519                 jne 0x797ba7
// 00797b8e  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00797b92  6aff                 push -1
// 00797b94  83c0f0               add eax, -0x10
// 00797b97  50                   push eax
// 00797b98  56                   push esi
// 00797b99  e8a2fdffff           call 0x797940
// 00797b9e  83c40c               add esp, 0xc
// 00797ba1  85c0                 test eax, eax
// 00797ba3  7554                 jne 0x797bf9
// 00797ba5  eb31                 jmp 0x797bd8
// 00797ba7  c6460600             mov byte ptr [esi + 6], 0
// 00797bab  8b4804               mov ecx, dword ptr [eax + 4]
// 00797bae  8b11                 mov edx, dword ptr [ecx]
// 00797bb0  807a0600             cmp byte ptr [edx + 6], 0
// 00797bb4  741d                 je 0x797bd3
// 00797bb6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00797bba  50                   push eax
// 00797bbb  56                   push esi
// 00797bbc  e8dff9ffff           call 0x7975a0
// 00797bc1  83c408               add esp, 8
// 00797bc4  85c0                 test eax, eax
// 00797bc6  7410                 je 0x797bd8
// 00797bc8  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00797bcb  8b5108               mov edx, dword ptr [ecx + 8]
// 00797bce  895608               mov dword ptr [esi + 8], edx
// 00797bd1  eb05                 jmp 0x797bd8
// 00797bd3  8b00                 mov eax, dword ptr [eax]
// 00797bd5  89460c               mov dword ptr [esi + 0xc], eax
// 00797bd8  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 00797bdb  2b4e28               sub ecx, dword ptr [esi + 0x28]
// 00797bde  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00797be3  f7e9                 imul ecx
// 00797be5  c1fa02               sar edx, 2
// 00797be8  8bca                 mov ecx, edx
// 00797bea  c1e91f               shr ecx, 0x1f
// 00797bed  03ca                 add ecx, edx
// 00797bef  51                   push ecx
// 00797bf0  56                   push esi
// 00797bf1  e84a6f0300           call 0x7ceb40
// 00797bf6  83c408               add esp, 8
// 00797bf9  5e                   pop esi
// 00797bfa  c3                   ret 
// library lua-5.1.1/ldo.c (function _resume)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
