// from server: 100% by auto
// roc 2011-06 007629a0  unit: seg_00760000  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007629a0
//
// 007629a0  55                   push ebp
// 007629a1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007629a5  85ed                 test ebp, ebp
// 007629a7  7510                 jne 0x7629b9
// 007629a9  8b442408             mov eax, dword ptr [esp + 8]
// 007629ad  8b4808               mov ecx, dword ptr [eax + 8]
// 007629b0  896908               mov dword ptr [ecx + 8], ebp
// 007629b3  83400810             add dword ptr [eax + 8], 0x10
// 007629b7  5d                   pop ebp
// 007629b8  c3                   ret 
// 007629b9  8bc5                 mov eax, ebp
// 007629bb  8d5001               lea edx, [eax + 1]
// 007629be  8bff                 mov edi, edi
// 007629c0  8a08                 mov cl, byte ptr [eax]
// 007629c2  40                   inc eax
// 007629c3  84c9                 test cl, cl
// 007629c5  75f9                 jne 0x7629c0
// 007629c7  53                   push ebx
// 007629c8  2bc2                 sub eax, edx
// 007629ca  56                   push esi
// 007629cb  8b742410             mov esi, dword ptr [esp + 0x10]
// 007629cf  8bd8                 mov ebx, eax
// 007629d1  8b4610               mov eax, dword ptr [esi + 0x10]
// 007629d4  8b5044               mov edx, dword ptr [eax + 0x44]
// 007629d7  57                   push edi
// 007629d8  3b5040               cmp edx, dword ptr [eax + 0x40]
// 007629db  7209                 jb 0x7629e6
// 007629dd  56                   push esi
// 007629de  e8bd470700           call 0x7d71a0
// 007629e3  83c404               add esp, 4
// 007629e6  8b7e08               mov edi, dword ptr [esi + 8]
// 007629e9  53                   push ebx
// 007629ea  55                   push ebp
// 007629eb  56                   push esi
// 007629ec  e82f780700           call 0x7da220
// 007629f1  83c40c               add esp, 0xc
// 007629f4  8907                 mov dword ptr [edi], eax
// 007629f6  c7470804000000       mov dword ptr [edi + 8], 4
// 007629fd  83460810             add dword ptr [esi + 8], 0x10
// 00762a01  5f                   pop edi
// 00762a02  5e                   pop esi
// 00762a03  5b                   pop ebx
// 00762a04  5d                   pop ebp
// 00762a05  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
