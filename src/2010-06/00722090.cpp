// from server: 100% by auto
// roc 2010-06 00722090  unit: RBX::UniversalTool  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00722090
//
// 00722090  8b442408             mov eax, dword ptr [esp + 8]
// 00722094  57                   push edi
// 00722095  8b7c2408             mov edi, dword ptr [esp + 8]
// 00722099  8bcf                 mov ecx, edi
// 0072209b  e800edffff           call 0x720da0
// 007220a0  83780806             cmp dword ptr [eax + 8], 6
// 007220a4  7404                 je 0x7220aa
// 007220a6  33c0                 xor eax, eax
// 007220a8  5f                   pop edi
// 007220a9  c3                   ret 
// 007220aa  8b08                 mov ecx, dword ptr [eax]
// 007220ac  80790600             cmp byte ptr [ecx + 6], 0
// 007220b0  8b542410             mov edx, dword ptr [esp + 0x10]
// 007220b4  56                   push esi
// 007220b5  741b                 je 0x7220d2
// 007220b7  83fa01               cmp edx, 1
// 007220ba  7c7d                 jl 0x722139
// 007220bc  0fb67107             movzx esi, byte ptr [ecx + 7]
// 007220c0  3bd6                 cmp edx, esi
// 007220c2  7f75                 jg 0x722139
// 007220c4  c1e204               shl edx, 4
// 007220c7  8d4c0a08             lea ecx, [edx + ecx + 8]
// 007220cb  befe08a000           mov esi, 0xa008fe
// 007220d0  eb22                 jmp 0x7220f4
// 007220d2  83fa01               cmp edx, 1
// 007220d5  8b7110               mov esi, dword ptr [ecx + 0x10]
// 007220d8  7c5f                 jl 0x722139
// 007220da  3b5624               cmp edx, dword ptr [esi + 0x24]
// 007220dd  7f5a                 jg 0x722139
// 007220df  8b761c               mov esi, dword ptr [esi + 0x1c]
// 007220e2  8b7496fc             mov esi, dword ptr [esi + edx*4 - 4]
// 007220e6  8b4c9110             mov ecx, dword ptr [ecx + edx*4 + 0x10]
// 007220ea  8b4908               mov ecx, dword ptr [ecx + 8]
// 007220ed  83c610               add esi, 0x10
// 007220f0  85f6                 test esi, esi
// 007220f2  7440                 je 0x722134
// 007220f4  834708f0             add dword ptr [edi + 8], -0x10
// 007220f8  8b5708               mov edx, dword ptr [edi + 8]
// 007220fb  53                   push ebx
// 007220fc  8b1a                 mov ebx, dword ptr [edx]
// 007220fe  8919                 mov dword ptr [ecx], ebx
// 00722100  8b5a04               mov ebx, dword ptr [edx + 4]
// 00722103  895904               mov dword ptr [ecx + 4], ebx
// 00722106  8b5208               mov edx, dword ptr [edx + 8]
// 00722109  895108               mov dword ptr [ecx + 8], edx
// 0072210c  8b4f08               mov ecx, dword ptr [edi + 8]
// 0072210f  ba04000000           mov edx, 4
// 00722114  395108               cmp dword ptr [ecx + 8], edx
// 00722117  5b                   pop ebx
// 00722118  7c1a                 jl 0x722134
// 0072211a  8b09                 mov ecx, dword ptr [ecx]
// 0072211c  f6410503             test byte ptr [ecx + 5], 3
// 00722120  7412                 je 0x722134
// 00722122  8b00                 mov eax, dword ptr [eax]
// 00722124  845005               test byte ptr [eax + 5], dl
// 00722127  740b                 je 0x722134
// 00722129  51                   push ecx
// 0072212a  50                   push eax
// 0072212b  57                   push edi
// 0072212c  e81f8e0500           call 0x77af50
// 00722131  83c40c               add esp, 0xc
// 00722134  8bc6                 mov eax, esi
// 00722136  5e                   pop esi
// 00722137  5f                   pop edi
// 00722138  c3                   ret 
// 00722139  5e                   pop esi
// 0072213a  33c0                 xor eax, eax
// 0072213c  5f                   pop edi
// 0072213d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
