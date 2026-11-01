// from server: 100% by auto
// roc 2009-12 00789190  unit: RBX::UniversalTool  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00789190
//
// 00789190  8b442408             mov eax, dword ptr [esp + 8]
// 00789194  56                   push esi
// 00789195  8b742408             mov esi, dword ptr [esp + 8]
// 00789199  8bce                 mov ecx, esi
// 0078919b  e850f4ffff           call 0x7885f0
// 007891a0  8b4808               mov ecx, dword ptr [eax + 8]
// 007891a3  83e906               sub ecx, 6
// 007891a6  7439                 je 0x7891e1
// 007891a8  83e901               sub ecx, 1
// 007891ab  7434                 je 0x7891e1
// 007891ad  83e901               sub ecx, 1
// 007891b0  7410                 je 0x7891c2
// 007891b2  8b4608               mov eax, dword ptr [esi + 8]
// 007891b5  c7400800000000       mov dword ptr [eax + 8], 0
// 007891bc  83460810             add dword ptr [esi + 8], 0x10
// 007891c0  5e                   pop esi
// 007891c1  c3                   ret 
// 007891c2  8b00                 mov eax, dword ptr [eax]
// 007891c4  8b5048               mov edx, dword ptr [eax + 0x48]
// 007891c7  8b4e08               mov ecx, dword ptr [esi + 8]
// 007891ca  83c048               add eax, 0x48
// 007891cd  8911                 mov dword ptr [ecx], edx
// 007891cf  8b5004               mov edx, dword ptr [eax + 4]
// 007891d2  895104               mov dword ptr [ecx + 4], edx
// 007891d5  8b4008               mov eax, dword ptr [eax + 8]
// 007891d8  894108               mov dword ptr [ecx + 8], eax
// 007891db  83460810             add dword ptr [esi + 8], 0x10
// 007891df  5e                   pop esi
// 007891e0  c3                   ret 
// 007891e1  8b10                 mov edx, dword ptr [eax]
// 007891e3  8b4e08               mov ecx, dword ptr [esi + 8]
// 007891e6  8b420c               mov eax, dword ptr [edx + 0xc]
// 007891e9  c7410805000000       mov dword ptr [ecx + 8], 5
// 007891f0  8901                 mov dword ptr [ecx], eax
// 007891f2  83460810             add dword ptr [esi + 8], 0x10
// 007891f6  5e                   pop esi
// 007891f7  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
