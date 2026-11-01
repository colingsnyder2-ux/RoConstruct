// from server: 100% by auto
// roc 2009-12 0079a8e0  unit: lua_exception  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a8e0
//
// 0079a8e0  8b442408             mov eax, dword ptr [esp + 8]
// 0079a8e4  8b4060               mov eax, dword ptr [eax + 0x60]
// 0079a8e7  53                   push ebx
// 0079a8e8  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0079a8ec  8b5328               mov edx, dword ptr [ebx + 0x28]
// 0079a8ef  56                   push esi
// 0079a8f0  8d0c40               lea ecx, [eax + eax*2]
// 0079a8f3  57                   push edi
// 0079a8f4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0079a8f8  8d34ca               lea esi, [edx + ecx*8]
// 0079a8fb  e820ffffff           call 0x79a820
// 0079a900  85c0                 test eax, eax
// 0079a902  7420                 je 0x79a924
// 0079a904  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0079a907  8b16                 mov edx, dword ptr [esi]
// 0079a909  8b71f0               mov esi, dword ptr [ecx - 0x10]
// 0079a90c  83e910               sub ecx, 0x10
// 0079a90f  c1e704               shl edi, 4
// 0079a912  8d5417f0             lea edx, [edi + edx - 0x10]
// 0079a916  8932                 mov dword ptr [edx], esi
// 0079a918  8b7104               mov esi, dword ptr [ecx + 4]
// 0079a91b  897204               mov dword ptr [edx + 4], esi
// 0079a91e  8b4908               mov ecx, dword ptr [ecx + 8]
// 0079a921  894a08               mov dword ptr [edx + 8], ecx
// 0079a924  834308f0             add dword ptr [ebx + 8], -0x10
// 0079a928  5f                   pop edi
// 0079a929  5e                   pop esi
// 0079a92a  5b                   pop ebx
// 0079a92b  c3                   ret 
// library lua-5.1/ldebug.c (function _lua_setlocal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
