// from server: 100% by auto
// roc 2009-12 00788710  unit: RBX::UniversalTool  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788710
//
// 00788710  56                   push esi
// 00788711  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00788715  57                   push edi
// 00788716  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0078871a  3bfe                 cmp edi, esi
// 0078871c  743e                 je 0x78875c
// 0078871e  53                   push ebx
// 0078871f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00788723  8bc3                 mov eax, ebx
// 00788725  f7d8                 neg eax
// 00788727  c1e004               shl eax, 4
// 0078872a  014708               add dword ptr [edi + 8], eax
// 0078872d  85db                 test ebx, ebx
// 0078872f  7e2a                 jle 0x78875b
// 00788731  33d2                 xor edx, edx
// 00788733  55                   push ebp
// 00788734  8b4e08               mov ecx, dword ptr [esi + 8]
// 00788737  8b4708               mov eax, dword ptr [edi + 8]
// 0078873a  03c2                 add eax, edx
// 0078873c  8d6910               lea ebp, [ecx + 0x10]
// 0078873f  896e08               mov dword ptr [esi + 8], ebp
// 00788742  8b28                 mov ebp, dword ptr [eax]
// 00788744  8929                 mov dword ptr [ecx], ebp
// 00788746  8b6804               mov ebp, dword ptr [eax + 4]
// 00788749  896904               mov dword ptr [ecx + 4], ebp
// 0078874c  8b4008               mov eax, dword ptr [eax + 8]
// 0078874f  83c210               add edx, 0x10
// 00788752  83eb01               sub ebx, 1
// 00788755  894108               mov dword ptr [ecx + 8], eax
// 00788758  75da                 jne 0x788734
// 0078875a  5d                   pop ebp
// 0078875b  5b                   pop ebx
// 0078875c  5f                   pop edi
// 0078875d  5e                   pop esi
// 0078875e  c3                   ret 
// library lua-5.1/lapi.c (function _lua_xmove)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
