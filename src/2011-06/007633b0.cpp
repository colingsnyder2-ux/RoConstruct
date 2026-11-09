// from server: 100% by auto
// roc 2011-06 007633b0  unit: seg_00760000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007633b0
//
// 007633b0  56                   push esi
// 007633b1  8b742408             mov esi, dword ptr [esp + 8]
// 007633b5  8b4610               mov eax, dword ptr [esi + 0x10]
// 007633b8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 007633bb  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 007633be  7209                 jb 0x7633c9
// 007633c0  56                   push esi
// 007633c1  e8da3d0700           call 0x7d71a0
// 007633c6  83c404               add esp, 4
// 007633c9  8b4614               mov eax, dword ptr [esi + 0x14]
// 007633cc  3b4628               cmp eax, dword ptr [esi + 0x28]
// 007633cf  7505                 jne 0x7633d6
// 007633d1  8b4648               mov eax, dword ptr [esi + 0x48]
// 007633d4  eb08                 jmp 0x7633de
// 007633d6  8b5004               mov edx, dword ptr [eax + 4]
// 007633d9  8b02                 mov eax, dword ptr [edx]
// 007633db  8b400c               mov eax, dword ptr [eax + 0xc]
// 007633de  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007633e2  50                   push eax
// 007633e3  51                   push ecx
// 007633e4  56                   push esi
// 007633e5  e8266f0700           call 0x7da310
// 007633ea  8b4e08               mov ecx, dword ptr [esi + 8]
// 007633ed  8901                 mov dword ptr [ecx], eax
// 007633ef  83c40c               add esp, 0xc
// 007633f2  c7410807000000       mov dword ptr [ecx + 8], 7
// 007633f9  83460810             add dword ptr [esi + 8], 0x10
// 007633fd  83c018               add eax, 0x18
// 00763400  5e                   pop esi
// 00763401  c3                   ret 
// library lua-5.1/lapi.c (function _lua_newuserdata)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
