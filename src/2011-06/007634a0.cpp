// from server: 100% by auto
// roc 2011-06 007634a0  unit: seg_00760000  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007634a0
//
// 007634a0  8b442408             mov eax, dword ptr [esp + 8]
// 007634a4  57                   push edi
// 007634a5  8b7c2408             mov edi, dword ptr [esp + 8]
// 007634a9  8bcf                 mov ecx, edi
// 007634ab  e800edffff           call 0x7621b0
// 007634b0  83780806             cmp dword ptr [eax + 8], 6
// 007634b4  7404                 je 0x7634ba
// 007634b6  33c0                 xor eax, eax
// 007634b8  5f                   pop edi
// 007634b9  c3                   ret 
// 007634ba  8b08                 mov ecx, dword ptr [eax]
// 007634bc  80790600             cmp byte ptr [ecx + 6], 0
// 007634c0  8b542410             mov edx, dword ptr [esp + 0x10]
// 007634c4  56                   push esi
// 007634c5  741b                 je 0x7634e2
// 007634c7  83fa01               cmp edx, 1
// 007634ca  7c7d                 jl 0x763549
// 007634cc  0fb67107             movzx esi, byte ptr [ecx + 7]
// 007634d0  3bd6                 cmp edx, esi
// 007634d2  7f75                 jg 0x763549
// 007634d4  c1e204               shl edx, 4
// 007634d7  8d4c0a08             lea ecx, [edx + ecx + 8]
// 007634db  becabea500           mov esi, 0xa5beca
// 007634e0  eb22                 jmp 0x763504
// 007634e2  83fa01               cmp edx, 1
// 007634e5  8b7110               mov esi, dword ptr [ecx + 0x10]
// 007634e8  7c5f                 jl 0x763549
// 007634ea  3b5624               cmp edx, dword ptr [esi + 0x24]
// 007634ed  7f5a                 jg 0x763549
// 007634ef  8b761c               mov esi, dword ptr [esi + 0x1c]
// 007634f2  8b7496fc             mov esi, dword ptr [esi + edx*4 - 4]
// 007634f6  8b4c9110             mov ecx, dword ptr [ecx + edx*4 + 0x10]
// 007634fa  8b4908               mov ecx, dword ptr [ecx + 8]
// 007634fd  83c610               add esi, 0x10
// 00763500  85f6                 test esi, esi
// 00763502  7440                 je 0x763544
// 00763504  834708f0             add dword ptr [edi + 8], -0x10
// 00763508  8b5708               mov edx, dword ptr [edi + 8]
// 0076350b  53                   push ebx
// 0076350c  8b1a                 mov ebx, dword ptr [edx]
// 0076350e  8919                 mov dword ptr [ecx], ebx
// 00763510  8b5a04               mov ebx, dword ptr [edx + 4]
// 00763513  895904               mov dword ptr [ecx + 4], ebx
// 00763516  8b5208               mov edx, dword ptr [edx + 8]
// 00763519  895108               mov dword ptr [ecx + 8], edx
// 0076351c  8b4f08               mov ecx, dword ptr [edi + 8]
// 0076351f  ba04000000           mov edx, 4
// 00763524  395108               cmp dword ptr [ecx + 8], edx
// 00763527  5b                   pop ebx
// 00763528  7c1a                 jl 0x763544
// 0076352a  8b09                 mov ecx, dword ptr [ecx]
// 0076352c  f6410503             test byte ptr [ecx + 5], 3
// 00763530  7412                 je 0x763544
// 00763532  8b00                 mov eax, dword ptr [eax]
// 00763534  845005               test byte ptr [eax + 5], dl
// 00763537  740b                 je 0x763544
// 00763539  51                   push ecx
// 0076353a  50                   push eax
// 0076353b  57                   push edi
// 0076353c  e84f3d0700           call 0x7d7290
// 00763541  83c40c               add esp, 0xc
// 00763544  8bc6                 mov eax, esi
// 00763546  5e                   pop esi
// 00763547  5f                   pop edi
// 00763548  c3                   ret 
// 00763549  5e                   pop esi
// 0076354a  33c0                 xor eax, eax
// 0076354c  5f                   pop edi
// 0076354d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
