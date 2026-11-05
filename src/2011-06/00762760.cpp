// from server: 100% by auto
// roc 2011-06 00762760  unit: seg_00760000  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762760
//
// 00762760  56                   push esi
// 00762761  8b742408             mov esi, dword ptr [esp + 8]
// 00762765  57                   push edi
// 00762766  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0076276a  8bc7                 mov eax, edi
// 0076276c  8bce                 mov ecx, esi
// 0076276e  e83dfaffff           call 0x7621b0
// 00762773  83780804             cmp dword ptr [eax + 8], 4
// 00762777  743e                 je 0x7627b7
// 00762779  50                   push eax
// 0076277a  56                   push esi
// 0076277b  e8404d0700           call 0x7d74c0
// 00762780  83c408               add esp, 8
// 00762783  85c0                 test eax, eax
// 00762785  7513                 jne 0x76279a
// 00762787  8b442414             mov eax, dword ptr [esp + 0x14]
// 0076278b  85c0                 test eax, eax
// 0076278d  7406                 je 0x762795
// 0076278f  c70000000000         mov dword ptr [eax], 0
// 00762795  5f                   pop edi
// 00762796  33c0                 xor eax, eax
// 00762798  5e                   pop esi
// 00762799  c3                   ret 
// 0076279a  8b4610               mov eax, dword ptr [esi + 0x10]
// 0076279d  8b4844               mov ecx, dword ptr [eax + 0x44]
// 007627a0  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 007627a3  7209                 jb 0x7627ae
// 007627a5  56                   push esi
// 007627a6  e8f5490700           call 0x7d71a0
// 007627ab  83c404               add esp, 4
// 007627ae  8bc7                 mov eax, edi
// 007627b0  8bce                 mov ecx, esi
// 007627b2  e8f9f9ffff           call 0x7621b0
// 007627b7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007627bb  85c9                 test ecx, ecx
// 007627bd  7407                 je 0x7627c6
// 007627bf  8b10                 mov edx, dword ptr [eax]
// 007627c1  8b520c               mov edx, dword ptr [edx + 0xc]
// 007627c4  8911                 mov dword ptr [ecx], edx
// 007627c6  8b00                 mov eax, dword ptr [eax]
// 007627c8  5f                   pop edi
// 007627c9  83c010               add eax, 0x10
// 007627cc  5e                   pop esi
// 007627cd  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tolstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
