// from server: 100% by auto
// roc 2007-03 005b96e0  unit: seg_005b0000  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b96e0
//
// 005b96e0  8b442408             mov eax, dword ptr [esp + 8]
// 005b96e4  56                   push esi
// 005b96e5  8b742408             mov esi, dword ptr [esp + 8]
// 005b96e9  57                   push edi
// 005b96ea  8bce                 mov ecx, esi
// 005b96ec  bf01000000           mov edi, 1
// 005b96f1  e8baf1ffff           call 0x5b88b0
// 005b96f6  8b4808               mov ecx, dword ptr [eax + 8]
// 005b96f9  83e906               sub ecx, 6
// 005b96fc  742f                 je 0x5b972d
// 005b96fe  2bcf                 sub ecx, edi
// 005b9700  741e                 je 0x5b9720
// 005b9702  2bcf                 sub ecx, edi
// 005b9704  7404                 je 0x5b970a
// 005b9706  33ff                 xor edi, edi
// 005b9708  eb2e                 jmp 0x5b9738
// 005b970a  8b08                 mov ecx, dword ptr [eax]
// 005b970c  8b5608               mov edx, dword ptr [esi + 8]
// 005b970f  8b52f0               mov edx, dword ptr [edx - 0x10]
// 005b9712  83c148               add ecx, 0x48
// 005b9715  8911                 mov dword ptr [ecx], edx
// 005b9717  c7410805000000       mov dword ptr [ecx + 8], 5
// 005b971e  eb18                 jmp 0x5b9738
// 005b9720  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b9723  8b10                 mov edx, dword ptr [eax]
// 005b9725  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 005b9728  894a0c               mov dword ptr [edx + 0xc], ecx
// 005b972b  eb0b                 jmp 0x5b9738
// 005b972d  8b5608               mov edx, dword ptr [esi + 8]
// 005b9730  8b08                 mov ecx, dword ptr [eax]
// 005b9732  8b52f0               mov edx, dword ptr [edx - 0x10]
// 005b9735  89510c               mov dword ptr [ecx + 0xc], edx
// 005b9738  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b973b  8b49f0               mov ecx, dword ptr [ecx - 0x10]
// 005b973e  f6410503             test byte ptr [ecx + 5], 3
// 005b9742  7413                 je 0x5b9757
// 005b9744  8b00                 mov eax, dword ptr [eax]
// 005b9746  f6400504             test byte ptr [eax + 5], 4
// 005b974a  740b                 je 0x5b9757
// 005b974c  51                   push ecx
// 005b974d  50                   push eax
// 005b974e  56                   push esi
// 005b974f  e84c010400           call 0x5f98a0
// 005b9754  83c40c               add esp, 0xc
// 005b9757  834608f0             add dword ptr [esi + 8], -0x10
// 005b975b  8bc7                 mov eax, edi
// 005b975d  5f                   pop edi
// 005b975e  5e                   pop esi
// 005b975f  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_setfenv)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
