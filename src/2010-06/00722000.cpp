// from server: 100% by auto
// roc 2010-06 00722000  unit: RBX::UniversalTool  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00722000
//
// 00722000  8b442408             mov eax, dword ptr [esp + 8]
// 00722004  57                   push edi
// 00722005  8b7c2408             mov edi, dword ptr [esp + 8]
// 00722009  8bcf                 mov ecx, edi
// 0072200b  e890edffff           call 0x720da0
// 00722010  83780806             cmp dword ptr [eax + 8], 6
// 00722014  7404                 je 0x72201a
// 00722016  33c0                 xor eax, eax
// 00722018  5f                   pop edi
// 00722019  c3                   ret 
// 0072201a  8b00                 mov eax, dword ptr [eax]
// 0072201c  80780600             cmp byte ptr [eax + 6], 0
// 00722020  56                   push esi
// 00722021  741f                 je 0x722042
// 00722023  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00722027  83f901               cmp ecx, 1
// 0072202a  7c56                 jl 0x722082
// 0072202c  0fb65007             movzx edx, byte ptr [eax + 7]
// 00722030  3bca                 cmp ecx, edx
// 00722032  7f4e                 jg 0x722082
// 00722034  c1e104               shl ecx, 4
// 00722037  8d4c0108             lea ecx, [ecx + eax + 8]
// 0072203b  b8fe08a000           mov eax, 0xa008fe
// 00722040  eb26                 jmp 0x722068
// 00722042  8b542414             mov edx, dword ptr [esp + 0x14]
// 00722046  83fa01               cmp edx, 1
// 00722049  8b7010               mov esi, dword ptr [eax + 0x10]
// 0072204c  7c34                 jl 0x722082
// 0072204e  3b5624               cmp edx, dword ptr [esi + 0x24]
// 00722051  7f2f                 jg 0x722082
// 00722053  8b449010             mov eax, dword ptr [eax + edx*4 + 0x10]
// 00722057  8b4808               mov ecx, dword ptr [eax + 8]
// 0072205a  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0072205d  8b4490fc             mov eax, dword ptr [eax + edx*4 - 4]
// 00722061  83c010               add eax, 0x10
// 00722064  85c0                 test eax, eax
// 00722066  7417                 je 0x72207f
// 00722068  8b31                 mov esi, dword ptr [ecx]
// 0072206a  8b5708               mov edx, dword ptr [edi + 8]
// 0072206d  8932                 mov dword ptr [edx], esi
// 0072206f  8b7104               mov esi, dword ptr [ecx + 4]
// 00722072  897204               mov dword ptr [edx + 4], esi
// 00722075  8b4908               mov ecx, dword ptr [ecx + 8]
// 00722078  894a08               mov dword ptr [edx + 8], ecx
// 0072207b  83470810             add dword ptr [edi + 8], 0x10
// 0072207f  5e                   pop esi
// 00722080  5f                   pop edi
// 00722081  c3                   ret 
// 00722082  5e                   pop esi
// 00722083  33c0                 xor eax, eax
// 00722085  5f                   pop edi
// 00722086  c3                   ret 
// library lua-5.1/lapi.c (function _lua_getupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
