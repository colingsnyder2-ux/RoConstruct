// from server: 100% by auto
// roc 2010-06 00720ec0  unit: RBX::UniversalTool  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00720ec0
//
// 00720ec0  56                   push esi
// 00720ec1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00720ec5  57                   push edi
// 00720ec6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00720eca  3bfe                 cmp edi, esi
// 00720ecc  743e                 je 0x720f0c
// 00720ece  53                   push ebx
// 00720ecf  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00720ed3  8bc3                 mov eax, ebx
// 00720ed5  f7d8                 neg eax
// 00720ed7  c1e004               shl eax, 4
// 00720eda  014708               add dword ptr [edi + 8], eax
// 00720edd  85db                 test ebx, ebx
// 00720edf  7e2a                 jle 0x720f0b
// 00720ee1  33d2                 xor edx, edx
// 00720ee3  55                   push ebp
// 00720ee4  8b4e08               mov ecx, dword ptr [esi + 8]
// 00720ee7  8b4708               mov eax, dword ptr [edi + 8]
// 00720eea  03c2                 add eax, edx
// 00720eec  8d6910               lea ebp, [ecx + 0x10]
// 00720eef  896e08               mov dword ptr [esi + 8], ebp
// 00720ef2  8b28                 mov ebp, dword ptr [eax]
// 00720ef4  8929                 mov dword ptr [ecx], ebp
// 00720ef6  8b6804               mov ebp, dword ptr [eax + 4]
// 00720ef9  896904               mov dword ptr [ecx + 4], ebp
// 00720efc  8b4008               mov eax, dword ptr [eax + 8]
// 00720eff  83c210               add edx, 0x10
// 00720f02  83eb01               sub ebx, 1
// 00720f05  894108               mov dword ptr [ecx + 8], eax
// 00720f08  75da                 jne 0x720ee4
// 00720f0a  5d                   pop ebp
// 00720f0b  5b                   pop ebx
// 00720f0c  5f                   pop edi
// 00720f0d  5e                   pop esi
// 00720f0e  c3                   ret 
// library lua-5.1/lapi.c (function _lua_xmove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
