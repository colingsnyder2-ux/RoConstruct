// from server: 100% by auto
// roc 2008-06 00612d30  unit: seg_00610000  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612d30
//
// 00612d30  8b442408             mov eax, dword ptr [esp + 8]
// 00612d34  57                   push edi
// 00612d35  8b7c2408             mov edi, dword ptr [esp + 8]
// 00612d39  8bcf                 mov ecx, edi
// 00612d3b  e850edffff           call 0x611a90
// 00612d40  83780806             cmp dword ptr [eax + 8], 6
// 00612d44  7404                 je 0x612d4a
// 00612d46  33c0                 xor eax, eax
// 00612d48  5f                   pop edi
// 00612d49  c3                   ret 
// 00612d4a  8b08                 mov ecx, dword ptr [eax]
// 00612d4c  80790600             cmp byte ptr [ecx + 6], 0
// 00612d50  8b542410             mov edx, dword ptr [esp + 0x10]
// 00612d54  56                   push esi
// 00612d55  741b                 je 0x612d72
// 00612d57  83fa01               cmp edx, 1
// 00612d5a  7c7d                 jl 0x612dd9
// 00612d5c  0fb67107             movzx esi, byte ptr [ecx + 7]
// 00612d60  3bd6                 cmp edx, esi
// 00612d62  7f75                 jg 0x612dd9
// 00612d64  c1e204               shl edx, 4
// 00612d67  8d4c0a08             lea ecx, [edx + ecx + 8]
// 00612d6b  be16b78000           mov esi, 0x80b716
// 00612d70  eb22                 jmp 0x612d94
// 00612d72  83fa01               cmp edx, 1
// 00612d75  8b7110               mov esi, dword ptr [ecx + 0x10]
// 00612d78  7c5f                 jl 0x612dd9
// 00612d7a  3b5624               cmp edx, dword ptr [esi + 0x24]
// 00612d7d  7f5a                 jg 0x612dd9
// 00612d7f  8b761c               mov esi, dword ptr [esi + 0x1c]
// 00612d82  8b7496fc             mov esi, dword ptr [esi + edx*4 - 4]
// 00612d86  8b4c9110             mov ecx, dword ptr [ecx + edx*4 + 0x10]
// 00612d8a  8b4908               mov ecx, dword ptr [ecx + 8]
// 00612d8d  83c610               add esi, 0x10
// 00612d90  85f6                 test esi, esi
// 00612d92  7440                 je 0x612dd4
// 00612d94  834708f0             add dword ptr [edi + 8], -0x10
// 00612d98  8b5708               mov edx, dword ptr [edi + 8]
// 00612d9b  53                   push ebx
// 00612d9c  8b1a                 mov ebx, dword ptr [edx]
// 00612d9e  8919                 mov dword ptr [ecx], ebx
// 00612da0  8b5a04               mov ebx, dword ptr [edx + 4]
// 00612da3  895904               mov dword ptr [ecx + 4], ebx
// 00612da6  8b5208               mov edx, dword ptr [edx + 8]
// 00612da9  895108               mov dword ptr [ecx + 8], edx
// 00612dac  8b4f08               mov ecx, dword ptr [edi + 8]
// 00612daf  ba04000000           mov edx, 4
// 00612db4  395108               cmp dword ptr [ecx + 8], edx
// 00612db7  5b                   pop ebx
// 00612db8  7c1a                 jl 0x612dd4
// 00612dba  8b09                 mov ecx, dword ptr [ecx]
// 00612dbc  f6410503             test byte ptr [ecx + 5], 3
// 00612dc0  7412                 je 0x612dd4
// 00612dc2  8b00                 mov eax, dword ptr [eax]
// 00612dc4  845005               test byte ptr [eax + 5], dl
// 00612dc7  740b                 je 0x612dd4
// 00612dc9  51                   push ecx
// 00612dca  50                   push eax
// 00612dcb  57                   push edi
// 00612dcc  e8af960400           call 0x65c480
// 00612dd1  83c40c               add esp, 0xc
// 00612dd4  8bc6                 mov eax, esi
// 00612dd6  5e                   pop esi
// 00612dd7  5f                   pop edi
// 00612dd8  c3                   ret 
// 00612dd9  5e                   pop esi
// 00612dda  33c0                 xor eax, eax
// 00612ddc  5f                   pop edi
// 00612ddd  c3                   ret 
// library lua-5.1/lapi.c (function _lua_setupvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
