// from server: 100% by auto
// roc 2009-12 007d11a0  unit: seg_007d0000  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d11a0
//
// 007d11a0  53                   push ebx
// 007d11a1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007d11a5  55                   push ebp
// 007d11a6  56                   push esi
// 007d11a7  57                   push edi
// 007d11a8  85db                 test ebx, ebx
// 007d11aa  7470                 je 0x7d121c
// 007d11ac  8b742414             mov esi, dword ptr [esp + 0x14]
// 007d11b0  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007d11b4  833e00               cmp dword ptr [esi], 0
// 007d11b7  753a                 jne 0x7d11f3
// 007d11b9  8b560c               mov edx, dword ptr [esi + 0xc]
// 007d11bc  8b4610               mov eax, dword ptr [esi + 0x10]
// 007d11bf  8d4c241c             lea ecx, [esp + 0x1c]
// 007d11c3  51                   push ecx
// 007d11c4  52                   push edx
// 007d11c5  50                   push eax
// 007d11c6  8b4608               mov eax, dword ptr [esi + 8]
// 007d11c9  ffd0                 call eax
// 007d11cb  83c40c               add esp, 0xc
// 007d11ce  85c0                 test eax, eax
// 007d11d0  7451                 je 0x7d1223
// 007d11d2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007d11d6  85c9                 test ecx, ecx
// 007d11d8  7449                 je 0x7d1223
// 007d11da  49                   dec ecx
// 007d11db  894604               mov dword ptr [esi + 4], eax
// 007d11de  890e                 mov dword ptr [esi], ecx
// 007d11e0  0fb610               movzx edx, byte ptr [eax]
// 007d11e3  40                   inc eax
// 007d11e4  894604               mov dword ptr [esi + 4], eax
// 007d11e7  83faff               cmp edx, -1
// 007d11ea  7437                 je 0x7d1223
// 007d11ec  41                   inc ecx
// 007d11ed  48                   dec eax
// 007d11ee  890e                 mov dword ptr [esi], ecx
// 007d11f0  894604               mov dword ptr [esi + 4], eax
// 007d11f3  8b4604               mov eax, dword ptr [esi + 4]
// 007d11f6  0fb608               movzx ecx, byte ptr [eax]
// 007d11f9  83f9ff               cmp ecx, -1
// 007d11fc  7425                 je 0x7d1223
// 007d11fe  8b3e                 mov edi, dword ptr [esi]
// 007d1200  3bdf                 cmp ebx, edi
// 007d1202  7702                 ja 0x7d1206
// 007d1204  8bfb                 mov edi, ebx
// 007d1206  57                   push edi
// 007d1207  50                   push eax
// 007d1208  55                   push ebp
// 007d1209  e8d83a0200           call 0x7f4ce6
// 007d120e  293e                 sub dword ptr [esi], edi
// 007d1210  017e04               add dword ptr [esi + 4], edi
// 007d1213  83c40c               add esp, 0xc
// 007d1216  03ef                 add ebp, edi
// 007d1218  2bdf                 sub ebx, edi
// 007d121a  7598                 jne 0x7d11b4
// 007d121c  5f                   pop edi
// 007d121d  5e                   pop esi
// 007d121e  5d                   pop ebp
// 007d121f  33c0                 xor eax, eax
// 007d1221  5b                   pop ebx
// 007d1222  c3                   ret 
// 007d1223  5f                   pop edi
// 007d1224  5e                   pop esi
// 007d1225  5d                   pop ebp
// 007d1226  8bc3                 mov eax, ebx
// 007d1228  5b                   pop ebx
// 007d1229  c3                   ret 
// library lua-5.1/lzio.c (function _luaZ_read)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lzio.c
