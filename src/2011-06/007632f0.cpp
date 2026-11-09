// from server: 100% by auto
// roc 2011-06 007632f0  unit: seg_00760000  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007632f0
//
// 007632f0  8b442408             mov eax, dword ptr [esp + 8]
// 007632f4  56                   push esi
// 007632f5  8b742408             mov esi, dword ptr [esp + 8]
// 007632f9  8bce                 mov ecx, esi
// 007632fb  e8b0eeffff           call 0x7621b0
// 00763300  8b4e08               mov ecx, dword ptr [esi + 8]
// 00763303  8b10                 mov edx, dword ptr [eax]
// 00763305  83e910               sub ecx, 0x10
// 00763308  51                   push ecx
// 00763309  52                   push edx
// 0076330a  56                   push esi
// 0076330b  e850610700           call 0x7d9460
// 00763310  83c40c               add esp, 0xc
// 00763313  85c0                 test eax, eax
// 00763315  7406                 je 0x76331d
// 00763317  83460810             add dword ptr [esi + 8], 0x10
// 0076331b  5e                   pop esi
// 0076331c  c3                   ret 
// 0076331d  834608f0             add dword ptr [esi + 8], -0x10
// 00763321  5e                   pop esi
// 00763322  c3                   ret 
// library lua-5.1/lapi.c (function _lua_next)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
