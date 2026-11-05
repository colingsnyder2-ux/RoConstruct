// from server: 100% by auto
// roc 2009-12 007894c0  unit: RBX::UniversalTool  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007894c0
//
// 007894c0  8b442408             mov eax, dword ptr [esp + 8]
// 007894c4  56                   push esi
// 007894c5  8b742408             mov esi, dword ptr [esp + 8]
// 007894c9  8b4e08               mov ecx, dword ptr [esi + 8]
// 007894cc  57                   push edi
// 007894cd  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007894d1  40                   inc eax
// 007894d2  c1e004               shl eax, 4
// 007894d5  57                   push edi
// 007894d6  2bc8                 sub ecx, eax
// 007894d8  51                   push ecx
// 007894d9  56                   push esi
// 007894da  e821e60000           call 0x797b00
// 007894df  83c40c               add esp, 0xc
// 007894e2  83ffff               cmp edi, -1
// 007894e5  750e                 jne 0x7894f5
// 007894e7  8b4614               mov eax, dword ptr [esi + 0x14]
// 007894ea  8b7608               mov esi, dword ptr [esi + 8]
// 007894ed  3b7008               cmp esi, dword ptr [eax + 8]
// 007894f0  7203                 jb 0x7894f5
// 007894f2  897008               mov dword ptr [eax + 8], esi
// 007894f5  5f                   pop edi
// 007894f6  5e                   pop esi
// 007894f7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_call)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
